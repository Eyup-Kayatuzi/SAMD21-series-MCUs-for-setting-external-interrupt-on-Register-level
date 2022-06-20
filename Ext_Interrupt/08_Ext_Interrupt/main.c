//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "sam.h"
#include "definitions.h"
#include "app.h"

//////////////////////////////////////////////////////////////////////////
// Function Prototypes
//////////////////////////////////////////////////////////////////////////
void ClocksInit(void);	// Configure Clock, Wait States and synch, bus clocks for 48MHz operation

int main(void)
{
	AppInit();
	PORT->Group[LED0_PORT].PINCFG[LED0_PIN_NUMBER].bit.DRVSTR = 1;
	PORT->Group[0].PINCFG[7].bit.PMUXEN = 1;
	PORT->Group[0].PMUX[3].bit.PMUXO = 0x0;
	NVIC_EnableIRQ(EIC_IRQn); // eic peripheral is enabled
	EIC->CONFIG[0].bit.FILTEN7 = 1;
	EIC->CONFIG[0].bit.SENSE7 = 0x2;
	EIC->INTENSET.bit.EXTINT7 = 1; // The external interrupt x is enabled. (pa7 for now)
	EIC->CTRL.bit.ENABLE = 1; // eic is enabled.
	while ((EIC->CTRL.bit.SWRST == 1) && (EIC->STATUS.bit.SYNCBUSY == 1))
	{
			
	}
	// Super loop
	while(1)
	{
		
		
		
	}
} 

void EIC_Handler(void)
{
	// if external interrupt detected
	if ( EIC->INTFLAG.bit.EXTINT7 == 1 )
	{
		// Turn the LED on PA17 ON
		REG_PORT_OUTSET0 = LED0_PIN_MASK;
		
		delay_ms(100);
		
		REG_PORT_OUTCLR0 = LED0_PIN_MASK;

		EIC->INTFLAG.bit.EXTINT7 = 1;
	}
}





