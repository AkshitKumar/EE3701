#include "LPC23xx.h"

void delay(unsigned int k)
{
unsigned int i,j;
for(i=0;i<=k;i++);
for(j=0;j<=0xFF;j++);
}

int  main ()
{
	unsigned int value=0;
    
     unsigned int max=0x3FF;

	PINSEL1 = 0x00200000; 		//Pinselection for uart tx and rx lines
	
	/************** Uart initialization **********************************/
    PCLKSEL0 = 0x00C00000;
    PINMODE1=0x00300000;
	FIO4DIR=0x00;
   
 while(1)
 {
		while(value < max){
			DACR = (value++) << 6;
			delay(0x01);
		}
		while(value > 0){
			DACR = (value--)<<6;
			delay(0x01);
		}
}
return 0;
}



