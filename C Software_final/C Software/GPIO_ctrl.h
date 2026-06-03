#ifndef GPIO_CTRL_H
#define GPIO_CTRL_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "./REGISTERS.h"



typedef unsigned short Uint16;
typedef unsigned int Uint32;


/******************************************************************************/
/*                              GPIO DIR									                    */
/******************************************************************************/

// GPA : OUTPUT
// GPB : INPUT

struct GPA_BITS{  
	Uint16 GPIO0:1;		// JC1
	Uint16 GPIO1:1;		// JC2
	Uint16 GPIO2:1; 	// JC3
	Uint16 GPIO3:1; 	// JC4
	Uint16 GPIO4:1; 	// JC7
	Uint16 GPIO5:1; 	// JC8
	Uint16 GPIO6:1; 	// JC9
	
	Uint16 RESERVED:9;
};

struct GPB_BITS{
	Uint16 GPIO7:1;		// JB1
	Uint16 GPIO8:1;		// JB2
	Uint16 GPIO9:1; 	// JB3
	Uint16 GPIO10:1; 	// JB4
	Uint16 GPIO11:1; 	// JB7
	Uint16 GPIO12:1; 	// JB8
	Uint16 GPIO13:1; 	// JB9
	
	Uint16 RESERVED:9;
};


union GPA_REG{
	Uint16  all;
	struct  GPA_BITS bit;
};

union GPB_REG{
	Uint16	all;			
	struct 	GPB_BITS bit;
};

struct GPIO_CTRL_REGS{
	union GPA_REG	GPADIR;
	union GPB_REG	GPBDIR;
};

/******************************************************************************/
/*                              GPIO DATA									                    */
/******************************************************************************/
struct GPADAT_BITS{
	Uint16 GPIO0:1;		// JC1
	Uint16 GPIO1:1;		// JC2
	Uint16 GPIO2:1; 	// JC3
	Uint16 GPIO3:1; 	// JC4
	Uint16 GPIO4:1; 	// JC7
	Uint16 GPIO5:1; 	// JC8
	Uint16 GPIO6:1; 	// JC9
	Uint16 RESERVED:9;
};

struct GPBDAT_BITS{
	Uint16 GPIO7:1;		// JB2
	Uint16 GPIO8:1;		// JB3
	Uint16 GPIO9:1; 	// JB4
	Uint16 GPIO10:1; 	// JB7
	Uint16 GPIO11:1; 	// JB8
	Uint16 GPIO12:1; 	// JB9
	Uint16 GPIO13:1; 	// JB10
	Uint16 RESERVED:9;
};

union GPADAT_REG{
	Uint16	all;
	struct GPADAT_BITS bit;
};

union GPBDAT_REG{
	Uint16	all;
	struct GPBDAT_BITS bit;
};




struct GPIO_DATA_REGS{
	union GPADAT_REG	GPASET;
	union GPADAT_REG	GPACLEAR;
	union GPBDAT_REG	GPBSET;
	union GPBDAT_REG	GPBCLEAR;
};



volatile struct GPIO_CTRL_REGS* const GpioCtrlRegsPtr = (volatile struct GPIO_CTRL_REGS*)(AHB_GPIO_BASE + GPIO_DIR);
#define GpioCtrlRegs (*GpioCtrlRegsPtr)

volatile struct GPIO_DATA_REGS* const GpioDataRegsPtr = (volatile struct GPIO_DATA_REGS*)(AHB_GPIO_BASE + GPIO_DATA);
#define GpioDataRegs (*GpioDataRegsPtr)



#define GPIO0 0
#define GPIO1 1
#define GPIO2 2
#define GPIO3 3
#define GPIO4 4
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7

int GPIO_SET(int GPIO)
{
	
	
}

int GPIO_CLEAR(int GPIO)
{
}

#endif // GPIO_CTRL_H


