#include "LPC23xx.h"


// delay routine 

void delay(void)
{
int i,j;
for(i=0; i<0x07;i++)
for(j=0; j<0XFF;j++);
}

/************************* main routine ************************************************************/
 //1010->0110->0101->1001->1010
 //1001->0101->0110->1010->1001


int main(void)
{


int k;
IODIR0 = 0XFFFFFFFF;
while(1)
{
 
  //forward
  IOPIN0=0X00000280;
  delay();
  
  IOPIN0=0X00000180;
  delay();
  
  IOPIN0=0X00000140;
  delay();
  
  IOPIN0=0X00000240;
  delay();
  
  
  //reverse
  IOPIN0=0X00000140;
  delay();
  
  IOPIN0=0X00000180;
  delay();
  
  IOPIN0=0X00000240;
  delay();
  
  IOPIN0=0X00000280;
  delay();
}

return 0;
}