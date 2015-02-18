// SPI setup code for pic24EP512GU810
SPI1STATbits.SPIEN = 0;	// Disable SPI 1 for setup
SPI1STATbits.SPISIDL=0;	// Operate during IDLE mode
SPI1STATbits.SPIEN = 0;	// Enable SPI 1 after setup

SPI1CON1bits.DISSCK = 0;	// SPIx clock on SCKx pin is enabled
SPI1CON1bits.DISSDO = 0;	// SDOx pin is controlled by the module
SPI1CON1bits.MODE16 = 1;	// Communication is word-wide (16 bits)
SPI1CON1bits.SMP = 0;	// Input data is sampled at the middle of data output time
SPI1CON1bits.CKE =	1;	// Serial output data changes on transition from active clock state to Idle clock state
SPI1CON1bits.SSEN = 0;	// SSx pin is not used by the module; pin is controlled by port function
SPI1CON1bits.CKP =	0;	// Idle state for clock is a low level; active state is a high level
SPI1CON1bits.MSTEN = 1;	// Master mode
SPI1CON1bits.SPRE = 0b110;	// Secondary prescale 2:1
SPI1CON1bits.PPRE= 0b11;	// Primary prescale 1:1

SPI1CON2bits.FRMEN = 0;	// Framed SPIx support is disabled
SPI1CON2bits.SPIFSD = 0;	// Frame sync pulse output (master)
SPI1CON2bits.FRMPOL = 0;	// Frame sync pulse is active-low
SPI1CON2bits.FRMDLY = 0;	// Frame sync pulse precedes the first bit clock
SPI1CON2bits.SPIBEN = 0;	// Enhanced buffer is disabled (Legacy mode)

