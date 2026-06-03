#ifndef SEGMENTS_H
#define SEGMENTS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "./REGISTERS.h"

typedef unsigned short Uint16;
typedef unsigned int Uint32;

	

typedef struct SEGMENT_CTRL_REGS{ 
	volatile Uint32 SEG3;
	volatile Uint32 SEG2;
	volatile Uint32 SEG1;
	volatile Uint32 SEG0;
} SEGMENT_REGS;

volatile struct SEGMENT_CTRL_REGS* const SegmentCtrlRegsPtr = (volatile struct SEGMENT_CTRL_REGS*)(AHB_SEG_BASE);
#define SegCtrlRegs (*SegmentCtrlRegsPtr)


#endif 