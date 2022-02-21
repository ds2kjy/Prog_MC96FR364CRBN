//////////////////////////////////////////////////////////
//	Device  	: MC96FR116
/////////////////////////////////////////////////////////
public  flash_program_mode_entry

FLASH_SELFPGM_ENTRY	SEGMENT   CODE
      	RSEG    FLASH_SELFPGM_ENTRY

flash_program_mode_entry:
   nop
   mov a,#0xaa         ;load Acc with AAH
   mov dph,#0x15       ;load DPH with 15H
   mov dpl,#0x55       ;load DPL with 55H
   db  0xa5              ;download @dptr with Acc. movc @(dptr++),a
   mov a,#0x55         ;load Acc with 55H
   mov dph,#0x1a       ;load DPH with 1AH
   mov dpl,#0xaa       ;load DPL with AAH
   db  0xa5              ;download @dptr with Acc. movc @(dptr++),a
   mov a,#0xa5         ;load Acc with A5H
   mov dph,#0x15       ;load DPH with 15H
   mov dpl,#0x55       ;load DPL with 55H
   db  0xa5              ;download @dptr with Acc. movc @(dptr++),a
   nop
   ret

end


