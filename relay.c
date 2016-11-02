#include "LPC23xx.h"


void  TargetResetInit(void)
{
  // 72 Mhz Frequency
  if ((PLLSTAT & 0x02000000) > 0)
  {
      /* If the PLL is already running   */
      PLLCON  &= ~0x02;                          /* Disconnect the PLL                                       */
      PLLFEED  =  0xAA;                          /* PLL register update sequence, 0xAA, 0x55                 */
      PLLFEED  =  0x55;
  }
  PLLCON   &= ~0x01;                            /* Disable the PLL                                          */
  PLLFEED   =  0xAA;                           /* PLL register update sequence, 0xAA, 0x55                 */
  PLLFEED   =  0x55;
  SCS      &= ~0x10;                         /* OSCRANGE = 0, Main OSC is between 1 and 20 Mhz           */
  SCS      |=  0x20;                         /* OSCEN = 1, Enable the main oscillator                    */
  while ((SCS &  0x40) == 0);
  CLKSRCSEL = 0x01;                         /* Select main OSC, 12MHz, as the PLL clock source          */
  PLLCFG    = (24 << 0) | (1 << 16);         /* Configure the PLL multiplier and divider                 */   
  PLLFEED   = 0xAA;                         /* PLL register update sequence, 0xAA, 0x55                 */
  PLLFEED   = 0x55;
  PLLCON   |= 0x01;                        /* Enable the PLL                                           */
  PLLFEED   = 0xAA;                        /* PLL register update sequence, 0xAA, 0x55                 */
  PLLFEED   = 0x55;
  CCLKCFG   = 3;                        /* Configure the ARM Core Processor clock divider           */
  USBCLKCFG = 5;                    /* Configure the USB clock divider                          */
  while ((PLLSTAT & 0x04000000) == 0);  
  PCLKSEL0  = 0xAAAAAAAA;                     /* Set peripheral clocks to be half of main clock           */
  PCLKSEL1  = 0x22AAA8AA;
  PLLCON   |= 0x02;                         /* Connect the PLL. The PLL is now the active clock source  */
  PLLFEED   = 0xAA;                          /* PLL register update sequence, 0xAA, 0x55                 */
  PLLFEED   = 0x55;
  while ((PLLSTAT & 0x02000000) == 0);  
  PCLKSEL0 = 0x55555555;  		     /* PCLK is the same as CCLK */
  PCLKSEL1 = 0x55555555;  
}

/*static void delay( unsigned int dv )
{
	volatile unsigned cnt;
	for ( cnt=0; cnt<=dv ; cnt++ );	
}*/

void delay(void)
{
	int i,j;
	for(i=0;i<=0x3fff;i++)
	for(j=0;j<=0xff;j++);
	
}
/************************* main routine ************************************************************/
int main (void)


{
	PINSEL6 = 0X00000000;	
	FIO3DIR = 0x050000FF; //relay connected to P3.24 and P3.26  (PORT 3 pins 24 and 26). 
	                       //so set direction as output as well as the LED port
    	
	TargetResetInit();
	while(1) 
	{
	FIO3SET =0X050000FF;   // Set the relay and LED pins to logic 1
		
		delay();
		FIO3CLR =0x050000FF;   // Clear the relay and LED pins (by assigning 1)
		
		delay();
	}
	return(0);
}


  
