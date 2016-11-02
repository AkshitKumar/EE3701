	TTL count-neg
	AREA Program, CODE, READONLY
	ENTRY
	
Main
	LDR R0, = Data1
	EOR R1,R1,R1
	LDR R2, Length
	CMP R2,#0
	BEQ Done
	
Loop
	LDR R3,[R0]
	CMP R3,#0
	BPL LoopTest
	ADD R1,R1,#1

LoopTest
	ADD R0,R0,#4
	SUBS R2,R2,#0x1
	BNE Loop

Done
	STR R1, Result
	SWI &11
	
	AREA Data1, DATA
	
Table DCD &F1522040
	     DCD &7F611C22
	     DCD &80000242
TablEnd DCD 0
	AREA Data2, DATA
Length DCW (TablEnd - Table)/4
	ALIGN
Result DCW 0
	END