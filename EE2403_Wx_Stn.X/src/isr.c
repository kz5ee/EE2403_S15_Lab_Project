


#include <stdio.h>
#include <p24Exxxx.h>


//<editor-fold defaultstate="collapsed" desc="Timer Interrupts">
void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;
    
    
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
    


    return;
}

 //</editor-fold>