	AREA Program, CODE, READONLY
	ENTRY
	
Main 
	LDR R1, Value1
	LDR R2, Value2
	CMP R1,R2
	BGT Greater
	LDR R0, =Result1
	STR R2, [R0]
	SWI &11
	
Greater 
	LDR R0, =Result1
	STR R1, [R0]
	SWI &11
	
Value1 DCD 0xCA23
Value2 DCD 0xCA24
	
	AREA DataRAM, DATA, READWRITE
Result1 DCD 0
	END
	