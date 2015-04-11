


#include <stdio.h>
#include <p24Exxxx.h>
#include "../inc/globals.h"


//<editor-fold defaultstate="collapsed" desc="Timer Interrupts">
void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;
    
    
    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T2Interrupt(void)
{
    _T2IF = 0;

    printf("TMR2 Interrupt fired\r\n");

    AD1CON1bits.ADON = 1;
    T2CONbits.TON = 0;

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
    _U1RXIF = 0;

    char received;
    received = U1RXREG;

    U1TXREG = received;

    return;
}
#ifdef _U2RXIF
    void __attribute__((interrupt,auto_psv)) _ISR _U2RXInterrupt(void)
{
    _U2RXIF = 0;

    char received;
    received = U2RXREG;



    if(received == '$')
    {
        printf("Received data from Temp/Pressure module\r\n");
    }


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
    //static int counter = 0;
    //static double ADAvg = 0;
    double ADValue, mph;
    //counter++;

    //printf("A2D Interrut has fired\r\n");
    
    ADRaw = ADC1BUF0;
    ADValue = (((ADRaw/ 4095.0)*(2.042))* 1000) - 402;
    
    //ADAvg = (ADAvg + ADValue) / counter;

    mph = ADValue / 22;
    
    //if(counter == 100)
    //{
       printf("ADC Value:  %d = %f mV = %f MPH Average:  \r\n",ADRaw,ADValue,mph);
       //counter = 0;
    //}

    

    //AD1CON1bits.ADON = 0;
    //T2CONbits.TON = 1;

    return;
}

 //</editor-fold>