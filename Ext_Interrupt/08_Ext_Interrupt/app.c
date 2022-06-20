//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "app.h"
#include "clock.h"

void AppInit(void)
{
	ClocksInit();
	
	// Assign LED0 as OUTPUT
	REG_PORT_DIR0 = LED0_PIN_MASK;
	// Set LED0 OFF
	REG_PORT_OUTCLR0 = LED0_PIN_MASK;
	

} // AppInit()


void AppRun(void)
{
	// Set the LED drive strength to strong
	PORT->Group[LED0_PORT].PINCFG[LED0_PIN_NUMBER].bit.DRVSTR = 1;

     //PORT->Group[EXT0_PORT].PINCFG[EXT0_PIN_NUMBER].reg = PORT_PINCFG_PMUXEN; // Pin pullup and enable MUX'ing
	PORT->Group[0].PINCFG[7].bit.PMUXEN = 1;
	 
     //PORT->Group[EXT0_PORT].PMUX[EXT0_PIN_NUMBER<<1].bit.PMUXE = MUX_PA07A_EIC_EXTINT7; // Set up IRQ-pin (PA7) to special function A (External Interrupt 7)
	PORT->Group[0].PMUX[3].bit.PMUXO = 0x0;
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NVIC_EnableIRQ(EIC_IRQn); // eic peripheral is enabled
	
	EIC->CONFIG[0].bit.FILTEN7 = 1;
	EIC->CONFIG[0].bit.SENSE7 = 0x2;
	EIC->INTENSET.bit.EXTINT7 = 1; // The external interrupt x is enabled.
	EIC->CTRL.bit.ENABLE = 1; // eic is enabled.
	while ((EIC->CTRL.bit.SWRST == 1) && (EIC->STATUS.bit.SYNCBUSY == 1))
	{
			
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
} // Apprun()