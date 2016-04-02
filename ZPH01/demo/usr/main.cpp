#include "stdlib.h"
#include "GPIO.h"
#include "USART.h"
#include "Interrupt.h"
#include "ZPH01.h"
#include "TaskManager.h"
#include "HCHO.h"

USART com(1,115200,true);   //USART1
USART sen(2,9600,true);   //USART1
USART WIFI(3,115200,true);   //USART3

//GPIO Beep(GPIOA,11,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
//GPIO Led(GPIOB,0,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);

ZPH01 senser(sen);

int main(){
	
	while(1)
	{
		if(senser.Updata())
		{
			com<<senser.GetData()<<"\t"<<senser.data_h<<"\t"<<senser.data_l<<"\n";
		}
		else
			com<<"ERROR!\n";
			tskmgr.DelayS(5);
	}

}

