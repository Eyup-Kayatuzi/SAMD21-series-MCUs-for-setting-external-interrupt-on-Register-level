
#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

// I/O Ports definitions
#define PORTA     (0ul)
#define PORTB     (1ul)

// LED0 IO Pin definition
#define LED0_PORT            PORTA
#define LED0_PIN_NUMBER      (17ul)
#define LED0_PIN_MASK        PORT_PA17

#define EXT0_PORT            PORTA
#define EXT0_PIN_NUMBER      (07ul)
#define EXT0_PIN_MASK        PORT_PA07

// GCLK_MAIN Clock output IO Pin Definition
#define GCLK_MAIN_OUTPUT_PORT       PORTA
#define GCLK_MAIN_OUTPUT_PIN_NUMBER (28ul)
#define GCLK_MAIN_OUTPUT_PIN_MASK   PORT_PA28

// Constants for Clock Generators
#define GENERIC_CLOCK_GENERATOR_MAIN      (0u)
#define GENERIC_CLOCK_GENERATOR_XOSC32K   (1u)

// initialized at reset for WDT
#define GENERIC_CLOCK_GENERATOR_OSCULP32K (2u) 
#define GENERIC_CLOCK_GENERATOR_OSC8M     (3u)

// Constants for Clock multiplexers
#define GENERIC_CLOCK_MULTIPLEXER_DFLL48M (0u)

// Constants for DFLL48M
#define MAIN_CLK_FREQ (48000000u)

// Assumes 32.768 kHz Crystal is connected
#define EXT_32K_CLK_FREQ (32768u)

#endif /* DEFINITIONS_H_ */