* Complement a 32bit number and store the result in RAM
   AREA Program, CODE, READONLY ;area where code is stored, usually from 0x00000000

   ENTRY
; main prgram starts after entry 
Main
  LDR R1, Value1   ;load value from const. stored in prog. memory
  MVN R1, R1       ; complement Value1  

  LDR R0, =Result  ;load pointer to Result in RAM (in 0x40000000) 
  STR R1, [R0]     ;store resultto that address pointed by R0
  
  LDR R2, [R0]     ;read back and check that stored value into R2
  
  SWI &11          ;software interrupt to terminate

;prog. memory constants
;note that constants are stored in prog. memory, just after the code end

Value1 DCD 0xCA23   ;first value stored in prog. memory

;RAM variables. Can't be initialized, except by writing there!
;need to define volatile variables only in RAM area, from 0x40000000
 
  AREA DataRAM, DATA, READWRITE ;define RAM location
Result DCD 0        ;space to store result in RAM

 END
