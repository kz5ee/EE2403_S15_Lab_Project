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
_FOSCSEL(FNOSC_FRC & IESO_OFF)
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & POSCMD_NONE & IOL1WAY_OFF)
_FWDT( WDTPOST_PS8192 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF & PLLKEN_ON)
_FPOR( FPWRT_PWR128 & BOREN_ON)
_FICD( ICS_PGD1 & JTAGEN_OFF)
_FAS(AWRP_OFF & APL_OFF & APLK_OFF)

#define FRC_FREQ 7370000
#define FCY (FRC_FREQ/2)

#include <libpic30.h>


int main(int argc, char** argv) {

    UART1_Config();
    UART2_Config();

    TRISFbits.TRISF3 = 0;
       
    //ChipInitialize();
    printf("May the Schwartz be with you\r\n");

    while(1)
    {
        __delay_ms(1000);
        LATFbits.LATF3 ^= 1;
        //printf("Hello\n");
    }




    return (EXIT_SUCCESS);
}