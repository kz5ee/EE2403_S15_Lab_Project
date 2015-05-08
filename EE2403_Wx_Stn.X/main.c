/* 
 * File:   main.c
 * Author: Mike
 *
 * Created on February 13, 2015, 7:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p24Exxxx.h>
#include <libpic30.h>
#include "inc/globals.h"
#include "inc/chip_setup.h"
#include "inc/Comms.h"
#include "inc/timers.h"
#include "inc/buffers.h"
#include "inc/gps.h"

/*
 * Words of Power (Configuration Words)
 * Refer to lines 50,605 - 50,961 in the PIC42EP512GU810.h header file.
 */

_FGS(GWRP_OFF & GSS_OFF & GSSK_OFF)
_FOSCSEL(FNOSC_FRC & IESO_OFF)
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & POSCMD_NONE)
_FWDT( WDTPOST_PS8192 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF)
_FPOR( FPWRT_PWR128 & BOREN_ON)
_FICD( ICS_PGD1 & JTAGEN_OFF)
_FAS(AWRP_OFF & APL_OFF & APLK_OFF)


int main(int argc, char** argv) {
    
    TRISFbits.TRISF3 = 0;
    LATFbits.LATF3 = 1;

    ChipInitialize();
    //SuppressGPS();
    //__C30_UART = 1;

    //U3TXREG = 0x30;
    
    printf("Weather station version 0.9.6\r\n");

    while(1)
    {
        if (U2STAbits.FERR)
        { printf("Framing Error on UART2\r\n"); }
    }




    return (EXIT_SUCCESS);
}