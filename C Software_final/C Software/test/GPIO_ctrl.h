#ifndef GPIO_CTRL_H
#define GPIO_CTRL_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "./REGISTERS.h"



typedef unsigned short Uint16;
typedef unsigned int Uint32;


/******************************************************************************/
/*                              GPIO SET									                    */
/******************************************************************************/

#define GPIO0 0x0001
#define GPIO1 0x0002
#define GPIO2 0x0004
#define GPIO3 0x0008
#define GPIO4 0x0010
#define GPIO5 0x0020
#define GPIO6 0x0040

typedef struct GPIO_CTRL_REGS{ 
	volatile Uint32 SET;
	volatile Uint32 CLEAR;
	volatile Uint32 ALL_SET;
	volatile Uint32 ALL_CLEAR;
} GPIO_REGS;

volatile struct GPIO_CTRL_REGS* const GpioCtrlRegsPtr = (volatile struct GPIO_CTRL_REGS*)(AHB_GPIO_BASE);
#define GpioCtrlRegs (*GpioCtrlRegsPtr)










// GPA : OUTPUT
// GPB : INPIT
/*
struct GPA_BITS{  
	Uint32 MASKED:8;
	Uint32 GPIO0:1;		// JC1
	Uint32 GPIO1:1;		// JC2
	Uint32 GPIO2:1; 	// JC3
	Uint32 GPIO3:1; 	// JC4
	Uint32 GPIO4:1; 	// JC7
	Uint32 GPIO5:1; 	// JC8
	Uint32 GPIO6:1; 	// JC9
	
	Uint32 RESERVED:9;
};

struct GPB_BITS{
	Uint32 MASKED:8;
	Uint32 GPIO7:1;		// JB1
	Uint32 GPIO8:1;		// JB2
	Uint32 GPIO9:1; 	// JB3
	Uint32 GPIO10:1; 	// JB4
	Uint32 GPIO11:1; 	// JB7
	Uint32 GPIO12:1; 	// JB8
	Uint32 GPIO13:1; 	// JB9
	
	Uint32 RESERVED:9;
};


union GPA_REG{
	Uint32  all;
	struct  GPA_BITS bit;
};

union GPB_REG{
	Uint32	all;			
	struct 	GPB_BITS bit;
};

struct GPIO_CTRL_REGS{
	union GPA_REG	GPADIR;
	union GPB_REG	GPBDIR;
};


struct GPADAT_BITS{
	Uint32 MASKED:8;
	Uint32 GPIO0:1;		// JC1
	Uint32 GPIO1:1;		// JC2
	Uint32 GPIO2:1; 	// JC3
	Uint32 GPIO3:1; 	// JC4
	Uint32 GPIO4:1; 	// JC7
	Uint32 GPIO5:1; 	// JC8
	Uint32 GPIO6:1; 	// JC9
	Uint32 RESERVED:9;
};

struct GPBDAT_BITS{
	Uint32 MASKED:8;
	Uint32 GPIO7:1;		// JB2
	Uint32 GPIO8:1;		// JB3
	Uint32 GPIO9:1; 	// JB4
	Uint32 GPIO10:1; 	// JB7
	Uint32 GPIO11:1; 	// JB8
	Uint32 RESERVED:11;
};

union GPADAT_REG{
	Uint32 all;
	struct GPADAT_BITS bit;
};

union GPBDAT_REG{
	Uint32	all;
	struct GPBDAT_BITS bit;
};




struct GPIO_DATA_REGS{
	union GPADAT_REG	GPASET;
	union GPBDAT_REG	GPBSET;
};

*/
/*
volatile struct GPIO_CTRL_REGS* const GpioCtrlRegsPtr = (volatile struct GPIO_CTRL_REGS*)(AHB_GPIO_BASE + GPIO_DIR);
#define GpioCtrlRegs (*GpioCtrlRegsPtr)

volatile struct GPIO_DATA_REGS* const GpioDataRegsPtr = (volatile struct GPIO_DATA_REGS*)(AHB_GPIO_BASE + GPIO_DATA);
#define GpioDataRegs (*GpioDataRegsPtr)



//volatile struct GPIO_CTRL_REGS* const GpioCtrlRegs = (volatile struct GPIO_CTRL_REGS*)(AHB_GPIO_BASE + GPIO_DIR);
//volatile struct GPIO_DATA_REGS* const GpioDataRegs = (volatile struct GPIO_DATA_REGS*)(AHB_GPIO_BASE + GPIO_DATA);

*/
#endif // GPIO_CTRL_H


