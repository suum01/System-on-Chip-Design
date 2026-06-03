#ifndef MOTOR_H
#define MOTOR_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "./REGISTERS.h"


volatile unsigned int *MotorCtrlPtr = (volatile unsigned int*) AHB_PWM_BASE;



#define MotorCtrl (*MotorCtrlPtr)



#endif 