/* 
 * File:   main.c
 * Author: Mike
 *
 * Created on February 13, 2015, 7:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <Generic.h>
//#include <p24Exxxx.h>
#include <xc.h>
#include "inc/chip_setup.h"
#include "inc/Comms.h"
#include "inc/timers.h"
#include "inc/buffers.h"


/*
 * Words of Power (Configuration Words)
 * Refer to lines 50,605 - 50,961 in the PIC42EP512GU810.h header file.
 */


_FGS(GWRP_OFF & GSS_OFF & GSSK_OFF)
_FOSCSEL(FNOSC_FRC & IESO_OFF)
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE)
_FWDT( WDTPOST_PS8192 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF & PLLKEN_ON)
_FPOR( FPWRT_PWR128 & BOREN_ON)
_FICD( ICS_PGD1 & JTAGEN_OFF)
_FAS(AWRP_OFF & APL_OFF & APLK_OFF)

#define FRC_FREQ 7370000
#define FCY (FRC_FREQ/2)

#include <libpic30.h>


int main(int argc, char** argv) {
    //dOSCTUN = 0x15;
// Configure PLL prescaler, PLL postscaler, PLL divisor
//PLLFBD=63; // M=65
//CLKDIVbits.PLLPOST=0; // N2=2
//CLKDIVbits.PLLPRE=1; // N1=3
//// Initiate Clock Switch to FRC oscillator with PLL (NOSC=0b001)
//__builtin_write_OSCCONH(0x01);
//__builtin_write_OSCCONL(OSCCON | 0x01);
//// Wait for Clock switch to occur
//while (OSCCONbits.COSC!= 0b001);
//// Wait for PLL to lock
//while (OSCCONbits.LOCK!= 1);

    
    //UART1_Config();
    //UART2_Config();

    TRISFbits.TRISF3 = 0;
       
    ChipInitialize();
    printf("Weather station version 0.7\r\n");

    while(1)
    {
        __delay_ms(1000);
        LATFbits.LATF3 ^= 1;
        //printf("Timer2 value is:  %d\r\n",TMR2);
        
    }




    return (EXIT_SUCCESS);
}