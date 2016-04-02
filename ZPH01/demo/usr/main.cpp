#include "../lib/USART.h"
#include "../lib/Interrupt.h"
#include "../lib/TaskManager.h"
#include "../usr/ZPH01.h"

USART com(1,115200,true);   //USART1
USART senser(2,9600,true);   //USART1

ZPH01 dust_senser(senser);

int main(){
	
	while(1)
	{
		if(dust_senser.Updata())
		{
			com<<dust_senser.GetData()<<"\t"<<dust_senser.mData_h<<"\t"<<dust_senser.mData_l<<"\n";
		}
		else
			com<<"ERROR!\n";
			tskmgr.DelayS(5);
	}

}

