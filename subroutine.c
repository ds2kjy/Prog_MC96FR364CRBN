//******************************************************************************
// Title			: subroutine.c
// Description		: timer, sub function, db etc
// Programming date	: 2014. 10. 23
//******************************************************************************


#include	"global.h"



unsigned int xdata gu16HalTimer = 0x0f00;	// dummy
unsigned int xdata gu16HalTimerT2 =0x0f00;	// dummy
unsigned int xdata gu16HalTimerT1 =0x0f00;	// dummy

///////////////////////////////////////////////////////////////////////////////////////////////
///	
/// 	Global variable for flash page buffer. Flash page buffer area : xdata[0x8000 ~ 0x807F(803f)
///	
///////////////////////////////////////////////////////////////////////////////////////////////
xdata unsigned char	gu8FlashPageBuffer[FLASH_BUFFER_SIZE] _at_ 0x8000;

///////////////////////////////////////////////////////////////////////////////////////////////
///	
/// 	Erases flash by 1 page(128 Bytes).
///
///	@param	void
///	@return	void
///	@note	When this function is called directly, the flash is not erased. 
///			It is valid only when called in HAL_FlashPageWrite().
///	
///////////////////////////////////////////////////////////////////////////////////////////////
void HAL_FlashPageErase(unsigned int u16FlashWordAddr)
{
	unsigned char	ib;

	/* Step 1. Enter the flash program mode */
	flash_program_mode_entry();

	/* Step 2. Reset page buffer */
	FECR = 0x00;
	_nop_(); _nop_(); _nop_();

	/* Step 3. Load page buffer. */
	for(ib = 0; ib < FLASH_BUFFER_SIZE; ib++)
	{
		gu8FlashPageBuffer[ib] = 0x00;
	}

	/* Step 4. Set page address. */
	FEARH = 0;		// Bank
	FEARM = (unsigned char)(u16FlashWordAddr>>8);
	FEARL = (unsigned char)u16FlashWordAddr & 0xFF;

	/* Step 5. Set erase time. */
	FETCR = 0xEA;      // 2.5ms @12MHz;

	/* Step 6. Start page erase */
	FECR = 0x03;		//erase_start(); 364b
//	FECR = 0x0B;		//erase_start(); 116c
	_nop_(); _nop_(); _nop_(); _nop_(); _nop_();	// 5 nop instructions recommended after cpu stop during for erase or write operation.

	/* Step 7. Wait process done */
	while((FESR & BIT7) == 0x00);

	/* Step 8. Exit from program mode */
	//FECR |= 0x30;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///	
/// 	Writes flash by 1 page(128 Bytes).
///
///	@param	u16CodeAddr	: Code address from which flash is written
///	@param	pu8ByteBuf	: Pointer to the buffer to be written.
///	@param	u8Option		: Option for writing
///				\n	bit[7:1]	: reserved
///				\n	bit[0]	: 1=Erasing only. Writing is not permitted.
///	@return	unsigned char. Status.
///	
///////////////////////////////////////////////////////////////////////////////////////////////
unsigned char HAL_FlashPageWrite(unsigned int u16CodeAddr, unsigned char* pu8ByteBuf, unsigned char u8Option)
{
	unsigned char	ib;
	unsigned char	u8Status;

//	unsigned char	code * pu8CodeBuf;
//	unsigned char	u8WriteLoop;
//	unsigned int	u16WriteSum;
//	unsigned int	u16ReadSum;
	unsigned char	u8EA;

	if(u16CodeAddr & (FLASH_BUFFER_SIZE-1))					// 64 OR 128 bytes align
	{
		assert_error(FLASH_CODE | RETURN_FLASH_ALIGN_FAILURE);
		return RETURN_FLASH_ALIGN_FAILURE;
	}

	SYS_WdtSet(1000);
	/* Step 1. Erase flash page */
	SYS_WdtSet(0);
	u8EA = EA;
	EA = 0;
	HAL_FlashPageErase(u16CodeAddr);

	if(u8Option & BIT0)
	{
		u8Status = RETURN_FLASH_SUCCESS;
		goto JP_HAL_FlashPageWrite;
	}

	/* Step 2. Enter the flash program mode */
	flash_program_mode_entry();

	/* Step 3. Page write. */
//	for(u8WriteLoop=0 ; u8WriteLoop<100 ; u8WriteLoop++)
	{


		/* Step 3-1. Reset page buffer */
		FECR = 0x00;
		_nop_();

		/* Step 3-2. Load page buffer. */
//		u16WriteSum = 0;
		for(ib = 0; ib < FLASH_BUFFER_SIZE; ib++)
		{
//			u16WriteSum += gu8FlashPageBuffer[ib] = pu8ByteBuf[ib];
			gu8FlashPageBuffer[ib] = pu8ByteBuf[ib];
		}
		_nop_(); _nop_(); _nop_();

		/* Step 3-3. Set page address. */
		FEARH = 0;		// Bank
		FEARM = (unsigned char)(u16CodeAddr >> 8);
		FEARL = (unsigned char)(u16CodeAddr & 0xFF);

		/* Step 3-4. Set write time. */
		FETCR = 0xEA;      // 2.5ms @12MHz;

		/* Step 3-5. Start page Write */
		FECR = 0x05;		//program_start();
		_nop_(); _nop_(); _nop_(); _nop_(); _nop_();	// 5 nop instructions recommended after cpu stop during for erase or write operation.

		/* Step 3-6. Wait process done */
		while((FESR & BIT7) == 0x00);
		u8Status = RETURN_FLASH_SUCCESS;
#if 0
		/* Step 3-7. Check written page */
		FEARL &= ~0x7F;
		pu8CodeBuf = u16CodeAddr;
		u16ReadSum = 0;
		for(ib=0; ib<FLASH_BUFFER_SIZE; ib++)
		{
			u16ReadSum += pu8CodeBuf[ib];
		}

		if(u16WriteSum == u16ReadSum)
		{
			u8Status = RETURN_FLASH_SUCCESS;
			break;
		}
		else
		{
			u8Status = RETURN_FLASH_PAGE_WRITE_FAIL;
		}
#endif
	}
	EA = u8EA;
	JP_HAL_FlashPageWrite :

	/* Step 4. Exit from program mode */
	FECR = 0x30;

	if(u8Status)
	{
		assert_error(FLASH_CODE | u8Status);
	}

	return u8Status;
}
//#ifndef _20_LITE
///////////////////////////////////////////////////////////////////////////////////////////////
///	
/// 	Reads flash.
///
///	@param	u16CodeAddr	: Code address from which flash is read.
///	@param	pu8ReadBuf	: Pointer to the buffer in which read flash is stored.
///	@param	u16ByteLen	: Number of bytes to read.
///	@return	unsigned char. Status.
///	
///////////////////////////////////////////////////////////////////////////////////////////////
unsigned char HAL_FlashRead(unsigned int u16CodeAddr, unsigned char* pu8ReadBuf, unsigned int u16ByteLen)
{
	unsigned int	iw;
	unsigned long	u32LastCodeAddr;
	unsigned char	code * pu8CodeBuf;

	unsigned int	u16ReadSum_1 = 0;
	unsigned int	u16ReadSum_2 = 0;

	u32LastCodeAddr = u16CodeAddr;
	u32LastCodeAddr += (u16ByteLen - 1);

	if(u32LastCodeAddr & 0xFFFF0000)
	{
		assert_error(FLASH_CODE | RETURN_FLASH_INVALID_ADDRESS);
		return RETURN_FLASH_INVALID_ADDRESS;
	}

	pu8CodeBuf = u16CodeAddr;
	for(iw=0 ; iw<u16ByteLen; iw++)
	{
		u16ReadSum_1 += pu8ReadBuf[iw] = pu8CodeBuf[iw];
	}

	// Check-Sum
	for(iw=0 ; iw<u16ByteLen ; iw++)
	{
		u16ReadSum_2 += pu8ReadBuf[iw];
	}
	
	// Compare Check-Sum & Return result
	if(u16ReadSum_1 == u16ReadSum_2)
	{
		return RETURN_FLASH_SUCCESS;
	}
	else
	{
		return RETURN_FLASH_PAGE_READ_FAIL;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///	
/// 	Global variable which indicates the number of TIMER0's ticks before watchdog reset.
///	
///////////////////////////////////////////////////////////////////////////////////////////////
unsigned int	gu16WdtResetTick;

///////////////////////////////////////////////////////////////////////////////////////////////
///	
/// Sets watchdog timer.
///
///	@param	u8Ena		: 0=Disable, 1=Enable.
///	@param	u8ResetDur	: 43.7ms * u8ResetDur(@ 12MHz)
///	@return	UINT8. Status.
///	
///////////////////////////////////////////////////////////////////////////////////////////////
void MC96_WdtSet(unsigned char u8Ena, unsigned char u8ResetDur)
{
	unsigned char	u8EA;

	u8EA = EA;
	EA = 0;

	WDTMR &= ~BIT7;

	if(u8Ena)
	{
		WDTR = u8ResetDur;
		WDTMR |= (BIT7|BIT5);
	}

	EA = u8EA;
}

void SYS_WdtSet(unsigned int u16Timer0Tick)
{
	unsigned char	u8EA;

	u8EA = EA;
	EA = 0;

	if(u16Timer0Tick)	// WDT enable
	{
		gu16WdtResetTick = u16Timer0Tick;
		MC96_WdtSet(1, 30);		// 43.7ms * 30 = 1Sec(@ 12MHz)
	} 
	else					// WDT disable
	{
		gu16WdtResetTick = 0;
		MC96_WdtSet(0, 0);
	}

	EA = u8EA;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///	
/// Restarts watchdog timer to prevent watchdog timeout.
///
///	@param	void
///	@return	void
///	
///////////////////////////////////////////////////////////////////////////////////////////////
void MC96_WdtRestart(void) large reentrant
{
	WDTMR |= BIT5;
}



 //======================================================
// interrupt routines
//======================================================


void INT_PCI0() interrupt 21
{
	// Pin change interrupt (P0)
	// TODO: add your code here
}
/*
unsigned char MsbtoLsb(unsigned char temp)
{
		unsigned char tempret;
		temp = (((temp & 0x1) << 7) | ((temp & 0x2) << 5) | ((temp & 0x4) << 3) | \
		((temp & 0x8) << 1) | ((temp & 0x10) >> 1 ) | ((temp & 0x20) >> 3) | \
		((temp & 0x40) >> 5) | ((temp & 0x80) >> 7) );
		tempret = temp;
		return	tempret; 
}
*/