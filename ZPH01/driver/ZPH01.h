#ifndef _ZPH01_H
#define _ZPH01_H

#include <stm32f10x.h>
#include "USART.h"

class ZPH01
{
	private:
	
		USART& mUsart;
		
		unsigned char mData[9];	//一帧数据大小
	
		float Concentration;//保存浓度值
	
		unsigned char FucCheckSum(unsigned char *i,unsigned char ln);//校验
	public:
	
		ZPH01(USART &usart);
		
		~ZPH01();
	
	  u8 data_h;//保存浓度半分比的整数部分
		u8 data_l;//保存小数部分
	
		bool  Updata();//更新
		float GetData();//返回浓度值 单位ug/m3
	
};


#endif


/*
   0-40   优
   40-80  良
   80-120 中
*/
