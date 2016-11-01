* Add and subtract two 32bit numbers and store the results in RAM
   AREA Program, CODE, READONLY ;area where code is stored, usually from 0x00000000

   ENTRY
; main prgram starts after entry 
Main
  LDR R1, Value1   ;load value from prog. memory
  LDR R2, Value2
  ADD R3, R1, R2   ;add and store in R3
  SUB R4, R1, R2   ;subtract

  LDR R0, =Result1  ;pointer to Result1 in RAM (in 0x40000000) 
  STR R3, [R0]      ;store to that address pointed by R0
  
  LDR R0, =Result2  ;pointer to Result2 in RAM (in 0x40000000) 
  STR R4, [R0]      ;store to that address pointed by R0

  SWI &11           ;SW interrupt

;prog. memory constants
;note that constants are stored in prog. memory, just after the code end

Value1 DCD 0xCA23   ;first value stored in prog. memory
Value2 DCD 0x1121   ;second value

;RAM variables. (Can't be initialized by compiler, except by writing there!)
;need to define volatile variables only in RAM area, from 0x40000000

  AREA DataRAM, DATA, READWRITE ;define RAM location
Result1 DCD 0        ;space to store result in RAM
Result2 DCD 0

 END
