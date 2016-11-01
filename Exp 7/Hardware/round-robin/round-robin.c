#include <lpc23xx.h>
void delay(void);
int main(){
	unsigned int a;
	FIO3DIR = 0x008000FF;
	FIO4DIR = 0x00;
	a = 0x1;
	while(1){
		delay();
		FIO3PIN0 = a;
		a = a << 1;
		if(a&(1<<7)){
			a = 0x1;
		}
	}
}

void delay(){
	int i;
	for(i=0;i<100000;i++);
}