#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "./REGISTERS.h"
#include "./GPIO_ctrl.h"
#include "./segments.h"
#include "./ALS_data.h"
#include "./MOTOR_ctrl.h"

//volatile static unsigned int min = 0;
//volatile static unsigned int sec = 0;

volatile static unsigned int remain_seat_num = 2;

volatile static unsigned int block_sensor_value = 0;
volatile static unsigned int parking_space1_sensor_value = 0;
volatile static unsigned int parking_space2_sensor_value = 0;

volatile static unsigned int parking_space1_flag = 0;
volatile static unsigned int parking_space2_flag = 0;


void Timer_ISR()
{
		block_sensor_value = *(unsigned int*) AHB_ALS0_BASE;
		parking_space1_sensor_value = *(unsigned int*) AHB_ALS1_BASE;
		parking_space2_sensor_value = *(unsigned int*) AHB_ALS2_BASE; 
	
	*(unsigned int*) (AHB_TIMER_BASE+0x0C) = 1;	//Clear timer interrupt request

}

void Key_ISR()
{
	 
/*
	SegCtrlRegs.SEG0 = 0x1;  // Set 7-segment display 0
	SegCtrlRegs.SEG1 = 0x1;  // Set 7-segment display 1
	SegCtrlRegs.SEG2 = 0x2;  // Set 7-segment display 2
	SegCtrlRegs.SEG3 = 0x5;  // Set 7-segment display 3
*/
}

void init(void)
{
	//Timer load register: =<clock frequency>
	*(unsigned int*) AHB_TIMER_BASE = 50000000;			  
	*(unsigned int*) (AHB_TIMER_BASE+8) = 0x03;
	
	// C99 option should be turned on!!
  *(unsigned int*) NVIC_INT_PRIORITY0 = 0x00004000; //IRQ0(Key): 0x00, IRQ1(Timer): 0x40
  *(unsigned int*) NVIC_INT_ENABLE = 0x00000003;    //Enable interrupts for key and timer

	
	// GPIO INITIALIZE
	GpioCtrlRegs.ALL_CLEAR = 1;   
  //GpioCtrlRegs.GPBDIR.all = 0x00;   
	//GpioDataRegs.GPBSET.all = 0x00;

	// 7SEGMETNS INITIALIZE
  *(unsigned int*) AHB_SEG_BASE = 0x0;             //set 7-segment display by zero
  *(unsigned int*) (AHB_SEG_BASE +0x04) = 0x0;    
  *(unsigned int*) (AHB_SEG_BASE +0x08)= 0x0;    
  *(unsigned int*) (AHB_SEG_BASE +0x0C)= 0x0;    
	
	
}
int sensor_process(void)
{
			if(block_sensor_value<=20) 
		{
				GpioCtrlRegs.SET = GPIO3;
				MotorCtrl = 0;
		}
		
		else if(block_sensor_value>20)  
		{
				GpioCtrlRegs.CLEAR = GPIO3;
				MotorCtrl = 1;
		}

		if(parking_space1_sensor_value<10) 
		{
				if(parking_space1_flag == 0)
				{
					remain_seat_num -= 1;
				}
				parking_space1_flag  =1;
				GpioCtrlRegs.CLEAR = GPIO1;
				//
		}
		
		else
		{
				if(parking_space1_flag == 1)
				{
					remain_seat_num += 1;
				}
				parking_space1_flag =0;
				GpioCtrlRegs.SET = GPIO1;
		}
		
		if(parking_space2_sensor_value<10) 
		{
				if(parking_space2_flag == 0)
				{
					remain_seat_num -= 1;
				}
				parking_space2_flag  =1;
				
				GpioCtrlRegs.CLEAR = GPIO2;

		}
		
		else 
		{
				if(parking_space2_flag == 1)
				{
					remain_seat_num += 1;
				}
				parking_space2_flag =0;
				GpioCtrlRegs.SET = GPIO2;				
		}
		
		return 0;
}


int main(void) 
{
	init();
  while (1)
	{		
		*(unsigned int*) AHB_SEG_BASE = remain_seat_num;
		//*(unsigned int*) (AHB_SEG_BASE +0x08)= parking_space2_sensor_value%10;    
		//*(unsigned int*) (AHB_SEG_BASE +0x0C)= parking_space2_sensor_value/10;    
		sensor_process();
	}

}