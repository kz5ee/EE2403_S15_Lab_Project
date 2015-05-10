


#include <stdio.h>
#include <p24Exxxx.h>
#include "../inc/buffers.h"
#include "../inc/globals.h"
#include "../inc/gps.h"
#include "../inc/temp_press.h"

static int adcounter = 1;
static int tpcounter = 0;
//<editor-fold defaultstate="collapsed" desc="Timer Interrupts">
void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;
    //printf("%d \r\n", adcounter);

    if(adcounter == 40)
    { U2TXREG = 0x13; }

    if(adcounter == 50)         //Have we got 5s worth of samples?
    {
        //U2TXREG = 0x13;         //Send command to get the Temp/Press. values
        //printf("ADC Value:  %d = %f mV  Average:  %.2f   => %.1f MPH\r\n",ADRaw,ADValue,ADAverage,mph);  //Make sure we've got reasonable values
        adcounter = 1;          //Reset the A2D counter

        PullGPSSentence(NMEACSV);
        //printf("%s\r\n",NMEACSV);
        PARSEGPSGGA = 1;

        
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
    _U1RXIF = 0;

    char db_received;
    db_received = U1RXREG;

    if (db_received == 0x1b)
    {
        U2TXREG = 0x13;
        printf("DC3 Command Sent\r\n");
    }

    if(db_received == 0x60)
    {
        U3TXREG = 0x14;
        printf("DC4 Command Sent\r\n");
    }

    return;
}
#ifdef _U2RXIF
    void __attribute__((interrupt,auto_psv)) _ISR _U2RXInterrupt(void)
{
    _U2RXIF = 0;
    char tp_received;
    tp_received = U2RXREG;

    //printf("%c",tp_received);

    if((tp_received != '*') && (tp_received != '&'))
    {
        TPString[tpcounter++] = tp_received;
    }

    if(tp_received == '$')
    {
        TPString[tpcounter] = '\0';
    }




    return;
}
#endif

#ifdef _U3RXIF
    void __attribute__((interrupt,auto_psv)) _ISR _U3RXInterrupt(void)
{
    _U3RXIF = 0;

    //printf("U3\r\n");
    
    char gps_received;
    gps_received = U3RXREG;
    //printf("%c",gps_received);

    RngAdd(gps_received);

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