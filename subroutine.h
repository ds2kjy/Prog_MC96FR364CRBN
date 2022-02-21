//******************************************************************************
// Title			: subroutine.h
// Description		: TxData Sort Variable define
// Programming date	: 2013.01.28.
//******************************************************************************
#ifndef _subroutine_H_
#define _subroutine_H_

#define FLASH_BUFFER_SIZE	64
#define	FLASH_CODE	0x0400

#define	RETURN_FLASH_SUCCESS				0x00
#define	RETURN_FLASH_INVALID_PARAMETER	0x11
#define	RETURN_FLASH_INVALID_ADDRESS	0x12
#define	RETURN_FLASH_ALIGN_FAILURE		0x14
#define	RETURN_FLASH_PAGE_WRITE_FAIL	0x15
#define	RETURN_FLASH_PAGE_READ_FAIL		0x16
#define assert_error(expr) (_nop_())
#define USER_DB_TABLE_ADDRESS	0x1f00		// 16kbyte size

extern void flash_program_mode_entry();
void HAL_FlashPageErase(unsigned int u16FlashWordAddr);
unsigned char HAL_FlashPageWrite(unsigned int u16CodeAddr, unsigned char* pu8ByteBuf, unsigned char u8Option);
unsigned char HAL_FlashRead(unsigned int u16CodeAddr, unsigned char* pu8ReadBuf, unsigned int u16ByteLen);
extern void SYS_WdtSet(unsigned int u16Timer0Tick);
unsigned char MsbtoLsb(unsigned char temp);						
extern unsigned int	u8T0DHL;



#endif
