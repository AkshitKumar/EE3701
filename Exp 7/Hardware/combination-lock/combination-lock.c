#include <lpc23xx.h>

int main(){
	unsigned int a = 0x28, b;
	FIO3DIR = 0x008000FF;
	FIO4DIR = 0x00;
	while(1){
		b = FIO4PIN0;
		if(a == b){
			FIO3PIN0 = 0xFF;
		}
		else{
			FIO3PIN0 = 0x00;
		}
	}
}