#include <lpc23xx.h>

int main(){
	unsigned int a,b,c;
	FIO3DIR = 0xFF;
	FIO4DIR = 0x00;
	while(1){
		a = FIO4PIN0;
		b = a >> 4;
		c = a - ( b << 4 );
		FIO3PIN0 = b + c;
	}
}