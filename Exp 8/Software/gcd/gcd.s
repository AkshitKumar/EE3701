		AREA Program, CODE, READONLY
		ENTRY
		
Main
		LDR R0, Value1
		LDR R1, Value2
		MOV R3, #0
		CMP R0, R3
		BEQ BaseCase
		
Loop
		CMP R0, R1
		BGT DecreaseR0
		SUB R1,R1,R0
		CMP R1,R3
		BNE Loop
		LDR R1, =Result
		STR R0, [R1]
		SWI &11
		
DecreaseR0
		SUB R0,R0,R1
		B Loop

BaseCase
		LDR R0, =Result
		STR R1,[R0]
		SWI &11
		
Value1 DCD &6
Value2 DCD &4
	
	AREA Data1,DATA,READWRITE
Result DCD 0
	END