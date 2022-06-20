//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "clock.h"

void ClocksInit(void)
{
	
	SYSCTRL->OSC8M.bit.PRESC = 0x00;  // divide by 1 
	SYSCTRL->OSC8M.bit.ENABLE = 1;
	
	
	GCLK->GENDIV.reg = 0x00000000; //*
	
	GCLK->GENCTRL.bit.SRC = 0x06; //* for OSC8M
	GCLK->GENCTRL.bit.DIVSEL = 0; //*
	GCLK->GENCTRL.bit.ID = 0x0; // * The Generic Clock Generator will be selected as the source of the generic clock by the ID bit group
	GCLK->GENCTRL.bit.GENEN = 1; //*
	
	//////////////////////////
	
	GCLK->CLKCTRL.bit.ID = 0x05; //* for eic peripheral 
	GCLK->CLKCTRL.bit.GEN = 0x0; //*
	GCLK->CLKCTRL.bit.CLKEN = 1; //* 
	
} 