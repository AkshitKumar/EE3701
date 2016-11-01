
//Program to read from switches and display on LED on the LPC2378 ARM kit 
#include<lpc23xx.h>

int main ()
{
		unsigned int a;

	FIO3DIR=0x008000FF ;  //Setting the lower 8 bits of PORT 3 ( 8 leds ) as output port
	FIO4DIR=0x00 ;// Setting the lower 8 bitsw of PORT 4 (8 switches) as input port
	
	while(1) 
	{
		a=FIO4PIN;// Read from the switch to variable a
		
		FIO3PIN=a;// Write variable a to leds
	
	}
	return 0;
}
