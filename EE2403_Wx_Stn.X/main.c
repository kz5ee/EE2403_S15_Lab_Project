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
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF)
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & POSCMD_NONE & IOL1WAY_OFF)
_FWDT( WDTPOST_PS8192 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF & PLLKEN_ON)
_FPOR( FPWRT_PWR128 & BOREN_ON)
_FICD( ICS_PGD1 & JTAGEN_OFF)
_FAS(AWRP_OFF & APL_OFF & APLK_OFF)


int main(int argc, char** argv) {
    void Ludacris_Speed_GO(void); //Function to set FOSC=140MHz
    Ludacris_Speed_GO();

    ANSELEbits.ANSE3 = 0;

    TRISEbits.TRISE3 = 0;

    UART1_Config();

       
    //ChipInitialize();
    printf("May the Schwartz be with you\r\n");

    while(1)
    {
        printf("Testing\r\n");
        LATEbits.LATE3 ^= 0;

    }



    return (EXIT_SUCCESS);
}

inline void Ludacris_Speed_GO()
{
    //This code from Microchip Family Ref. 39 Oscillator(Part III)
    //Configure PLL prescaler, PLL postscaler, PLL divisor

    OSCTUN = 0x15;  //Tune Oscillator to 8 MHz

    PLLFBD = 68; // M = 40
    CLKDIVbits.PLLPOST = 0; // N2 = 2
    CLKDIVbits.PLLPRE = 0; // N1 = 2
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while(OSCCONbits.LOCK != 1) {};
    return;
}