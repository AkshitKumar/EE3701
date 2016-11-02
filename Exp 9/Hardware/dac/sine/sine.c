#include "LPC23xx.h"

void delay(unsigned int k)
{
unsigned int i,j;
for(i=0;i<=k;i++);
for(j=0;j<=0xFF;j++);
}

int sine[255] = {0x200,0x20c,0x219,0x225,0x232,0x23e,0x24b,0x257,
0x264,0x270,0x27c,0x288,0x295,0x2a1,0x2ac,0x2b8,
0x2c4,0x2d0,0x2db,0x2e6,0x2f1,0x2fd,0x307,0x312,
0x31d,0x327,0x331,0x33b,0x345,0x34f,0x358,0x361,
0x36a,0x373,0x37c,0x384,0x38c,0x394,0x39b,0x3a3,
0x3aa,0x3b1,0x3b7,0x3be,0x3c4,0x3c9,0x3cf,0x3d4,
0x3d9,0x3de,0x3e2,0x3e6,0x3ea,0x3ed,0x3f0,0x3f3,
0x3f6,0x3f8,0x3fa,0x3fc,0x3fd,0x3fe,0x3ff,0x3ff,
0x3ff,0x3ff,0x3fe,0x3fd,0x3fc,0x3fb,0x3f9,0x3f7,
0x3f4,0x3f2,0x3ef,0x3eb,0x3e8,0x3e4,0x3e0,0x3db,
0x3d7,0x3d1,0x3cc,0x3c7,0x3c1,0x3ba,0x3b4,0x3ad,
0x3a6,0x39f,0x398,0x390,0x388,0x380,0x377,0x36f,
0x366,0x35d,0x353,0x34a,0x340,0x336,0x32c,0x322,
0x317,0x30d,0x302,0x2f7,0x2ec,0x2e1,0x2d5,0x2ca,
0x2be,0x2b2,0x2a7,0x29b,0x28f,0x282,0x276,0x26a,
0x25d,0x251,0x245,0x238,0x22c,0x21f,0x212,0x206,
0x1f9,0x1ed,0x1e0,0x1d3,0x1c7,0x1ba,0x1ae,0x1a2,
0x195,0x189,0x17d,0x170,0x164,0x158,0x14d,0x141,
0x135,0x12a,0x11e,0x113,0x108,0xfd,0xf2,0xe8,
0xdd,0xd3,0xc9,0xbf,0xb5,0xac,0xa2,0x99,
0x90,0x88,0x7f,0x77,0x6f,0x67,0x60,0x59,
0x52,0x4b,0x45,0x3e,0x38,0x33,0x2e,0x28,
0x24,0x1f,0x1b,0x17,0x14,0x10,0xd,0xb,
0x8,0x6,0x4,0x3,0x2,0x1,0x0,0x0,
0x0,0x0,0x1,0x2,0x3,0x5,0x7,0x9,
0xc,0xf,0x12,0x15,0x19,0x1d,0x21,0x26,
0x2b,0x30,0x36,0x3b,0x41,0x48,0x4e,0x55,
0x5c,0x64,0x6b,0x73,0x7b,0x83,0x8c,0x95,
0x9e,0xa7,0xb0,0xba,0xc4,0xce,0xd8,0xe2,
0xed,0xf8,0x102,0x10e,0x119,0x124,0x12f,0x13b,
0x147,0x153,0x15e,0x16a,0x177,0x183,0x18f,0x19b,
0x1a8,0x1b4,0x1c1,0x1cd,0x1da,0x1e6,0x1f3};


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
  DACR = sine[(value++)%255] << 6;
	delay(0x01);
}
return 0;
}


