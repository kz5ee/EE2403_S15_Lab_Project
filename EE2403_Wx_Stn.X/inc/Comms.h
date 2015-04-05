/* 
 * File:   Comms.h
 * Author: Mike
 *
 * Created on February 13, 2015, 9:02 PM
 */

#ifndef COMMS_H
#define	COMMS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <p24Exxxx.h>
#include <Generic.h>
#include <uart.h>
#include <spi.h>
//#include <i2c.h>
#include <pps.h>

#define __FOSC_ 140000000
#define __FTCY_ (__FOSC_/2)

    //<editor-fold defaultstate="collapsed" desc="UART Configuration">
    
#define __U1BAUD_ 9600L //<--- Desired Baud rate UART1 CHANGE THIS
#define __BAUDUART1_ ((__FTCY_/(16*__U1BAUD_))-1)

extern void UART1_Config(void);

#ifdef _U2RXIF

#define __U2BAUD_ 2400L //Desired baud rate UART2 CHANGE THIS
#define __BAUDUART2_ ((__FTCY_/(16*__U2BAUD_))-1)

extern void UART2_Config(void);

#endif

#ifdef _U3RXIF
#define __U3BAUD_ 2400L //Desired baud rate UART3 CHANGE THIS
#define __BAUDUART3_ ((__FTCY_/(16*__U3BAUD_))-1)

extern void UART3_Config(void);

#endif

#ifdef _U4RXIF
#define __U4BAUD_ 2400L //Desired baud rate UART3 CHANGE THIS
#define __BAUDUART4_ ((__FTCY_/(16*__U4BAUD_))-1)

extern void UART3_Config(void);

#endif
    //</editor-fold>

    //<editor-fold defaultstate="collapsed" desc="SPI Configuration">



    //</editor-fold>

//    //<editor-fold defaultstate="collapsed" desc="I2C Configuration">
//
//
//
//    //</editor-fold>


#ifdef	__cplusplus
}
#endif

#endif	/* COMMS_H */

