#ifndef MOTOR_H
#define MOTOR_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "./REGISTERS.h"


volatile unsigned int *MOTOR = (volatile unsigned int*) AHB_PWM_BASE;



#define AlsData0 (*ALS0);



#endif 