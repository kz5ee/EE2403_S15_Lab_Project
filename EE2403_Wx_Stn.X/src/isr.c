


#include <stdio.h>
#include <p24Exxxx.h>
#include "../inc/globals.h"

static int adcounter = 1;

//<editor-fold defaultstate="collapsed" desc="Timer Interrupts">
void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;

    
    if(adcounter == 50)         //Have we got 5s worth of samples?
    {
        //U2TXREG = 0x13;         //Send command to get the Temp/Press. values
        //printf("ADC Value:  %d = %f mV  Average:  %.2f   => %.1f MPH\r\n",ADRaw,ADValue,ADAverage,mph);  //Make sure we've got reasonable values
        adcounter = 1;          //Reset the A2D counter
    }
    else
    {
        AD1CON1bits.SAMP = 1;   //We want to get an A2D sample
    }

    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T2Interrupt(void)
{
    _T2IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T3Interrupt(void)
{
    _T3IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T4Interrupt(void)
{
    _T4IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T5Interrupt(void)
{
    _T5IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T6Interrupt(void)
{
    _T6IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T7Interrupt(void)
{
    _T7IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T8Interrupt(void)
{
    _T8IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T9Interrupt(void)
{
    _T9IF = 0;


    return;
}

//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="UART RX Interrupts">
    void __attribute__((interrupt,auto_psv)) _ISR _U1RXInterrupt(void)
{
        //static int count =0;
    _U1RXIF = 0;
    printf("U1\r\n");
    char received;
    received = U1RXREG;
    U1TXREG = received;
//    U1RXDat[count] = received;
//    count++;

    
    //printf("U1RX Fired\r\n");
    

    
    if (received == 0x60)
    {
        U2TXREG = 0x13;
        printf("Command Sent\r\n");
    }

    //printf("%s \r\n",U1RXDat);

    return;
}
#ifdef _U2RXIF
    void __attribute__((interrupt,auto_psv)) _ISR _U2RXInterrupt(void)
{
    _U2RXIF = 0;
    //printf("U2\r\n");

    char received;
    received = U2RXREG;

    printf("%c",received);

    return;
}
#endif

#ifdef _U3RXIF
    void __attribute__((interrupt,auto_psv)) _ISR _U3RXInterrupt(void)
{
    _U3RXIF = 0;


    return;
}
#endif

#ifdef _U4RXIF
    void __attribute__((interrupt,auto_psv)) _ISR _U4RXInterrupt(void)
{
    _U4RXIF = 0;


    return;
}
#endif
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="ADC Interrupt">
       void __attribute__((interrupt,auto_psv)) _ISR _AD1Interrupt(void)
{
    _AD1IF = 0;
        
    ADRaw = ADC1BUF0;
    ADValue = (((ADRaw / 4096.0)*(2.042))* 1000) - 400;
    
    ADAverage = (ADAverage + ADValue) / (double)adcounter;
    adcounter++;

       
    

    return;
}

 //</editor-fold>