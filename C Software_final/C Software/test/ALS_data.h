#ifndef ALS_DATA_H
#define ALS_DATA_H

#include <stdint.h>
#include "./REGISTERS.h"



volatile unsigned int *ALS0 = (volatile unsigned int*) AHB_ALS0_BASE;
volatile unsigned int *ALS1 = (volatile unsigned int*) AHB_ALS1_BASE;
volatile unsigned int *ALS2 = (volatile unsigned int*) AHB_ALS2_BASE;

#define AlsData0 (*ALS0);
#define AlsData1 (*ALS1);
#define AlsData2 (*ALS2);


#endif 