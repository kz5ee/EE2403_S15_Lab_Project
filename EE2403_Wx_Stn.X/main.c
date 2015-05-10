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
    SuppressGPS();
    //__C30_UART = 1;

    //U3TXREG = 0x30;
    
    printf("Weather station version 0.9.7\r\n");

    while(1)
    {
        //if (U3STAbits.FERR)
        //{ printf("Framing Error on UART3\r\n"); }
        
        //if (U3STAbits.OERR)
        //{ printf("Overrun error on UART3\r\n"); U3STAbits.OERR = 0;}

        if(PARSEGPSGGA == 1)
        {
            TokenizeGpsSentence(NMEACSV, token);
            ParseGGA(token);
            //ParseDegMin(Latitude, Longitude);

            LatMin = DegMinToDeg(Latitude);
            LonMin = DegMinToDeg(Longitude);

            //printf("Location:  %f %c, %f %c\r\n",LatMin, LatHemi, LonMin, LonHemi);

            //printf("Latitude:  %d° %.5f' %c  Longitude:  %d° %.5f' %c\r\n",LatDeg, LatMin, LatHemi, LonDeg, LonMin, LonHemi);

            PARSEGPSGGA = 0;

            //T1CONbits.TON = 1;

        }
        
//        while(BusyUART3());
//        WriteUART3(0x4d);
//        while(BusyUART3());
//        WriteUART3(0x0d);
//        while(BusyUART3());
//        WriteUART3(0x0a);


    }




    return (EXIT_SUCCESS);
}