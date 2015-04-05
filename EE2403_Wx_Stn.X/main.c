/* 
 * File:   main.c
 * Author: Mike
 *
 * Created on February 13, 2015, 7:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p24Exxxx.h>
#include "inc/chip_setup.h"
#include "inc/Comms.h"
#include "inc/timers.h"
#include "inc/buffers.h"

/*
 * Words of Power (Configuration Words)
 * Refer to lines 50,605 - 50,961 in the PIC42EP512GU810.h header file.
 */

_FGS(GWRP_OFF & GSS_OFF & GSSK_OFF)
_FOSCSEL(FNOSC_FRCPLL & IESO_ON)
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE)
_FWDT( WDTPOST_PS8192 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF & PLLKEN_ON)
_FPOR( FPWRT_PWR128 & BOREN_ON)
_FICD( ICS_PGD1 & JTAGEN_OFF)
_FAS(AWRP_OFF & APL_OFF & APLK_OFF)


int main(int argc, char** argv) {
    void Ludacris_Speed_GO(void); //Function to set FOSC=140MHz
    Ludacris_Speed_GO();

    ANSELCbits.ANSC1 = 0;
    ANSELEbits.ANSE4 = 0;
    ANSELEbits.ANSE3 = 0;

    TRISDbits.TRISD9 = 0;
    TRISEbits.TRISE3 = 0;

    //UART1_Config();

    LATDbits.LATD9 = 1;
    
    //ChipInitialize();
    printf("May the Schwartz be with you\r\n");

    while(1)
    {
        printf("Testing\r\n");
        LATEbits.LATE3 ^= 0;

    }



    return (EXIT_SUCCESS);
}

inline void Ludacris_Speed_GO(void)
{
    // Configure PLL prescaler, PLL postscaler, PLL divisor
PLLFBD=74; // M=76
CLKDIVbits.PLLPOST=0; // N2=2
CLKDIVbits.PLLPRE=0; // N1=2
// Initiate Clock Switch to FRC oscillator with PLL (NOSC=0b001)
__builtin_write_OSCCONH(0x01);
__builtin_write_OSCCONL(OSCCON | 0x01);
// Wait for Clock switch to occur
while (OSCCONbits.COSC!= 0b001);
// Wait for PLL to lock
while (OSCCONbits.LOCK!= 1);
}