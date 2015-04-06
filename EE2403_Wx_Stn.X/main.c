/* 
 * File:   main.c
 * Author: Mike
 *
 * Created on February 13, 2015, 7:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <Generic.h>
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

    int ADCRaw;
    double ADCVal;

    //UART1_Config();
    //UART2_Config();

    TRISFbits.TRISF3 = 0;
       
    ChipInitialize();
    printf("May the Schwartz be with you\r\n");

    while(1)
    {
        __delay_ms(100);
        //LATFbits.LATF3 ^= 1;
        //printf("Hello\n");
        AD1CON1bits.SAMP = 1;
        __delay_us(10);
        AD1CON1bits.SAMP = 0;
        while(!AD1CON1bits.DONE);
        AD1CON1bits.DONE = 0;
        ADCRaw = ADC1BUF0;

        ADCVal = (ADCRaw/1024.0)*(2.048);

        printf("ADC Value is %f\n", ADCVal);
    }




    return (EXIT_SUCCESS);
}