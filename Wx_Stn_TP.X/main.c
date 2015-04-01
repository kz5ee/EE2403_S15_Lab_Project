/* File:   main.c
 * Author: Mike Peters, Dustin Craig Keefer
 * Created on March 30, 2015, 8:49 AM
 */

// PIC16F1823 Configuration Bit Settings
// 'C' source line config statements
#include <xc.h>
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)
// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

#include <stdio.h>
#include <stdlib.h>
#include <pic16f1823.h>

int i=0;    //Counting Variable
/*
 * 
 */
int main(void)
{
    // Initialize Chip
    OSCCONbits.SCS = 0b11;      // Use Internat HFINTOSC (16MHz Default)
    OSCCONbits.SPLLEN = 0;      // PLL Disabled
    OSCCONbits.IRCF = 0b1101;   // Use 4MHz HF

    TRISAbits.TRISA5 = 0;   // Set pin 2 as an output for LED

    TRISAbits.TRISA4 = 1;   // Set pin 3 as an input for Pressure Sensor
    ANSELAbits.ANSA4 = 1;   // Set pin 3 as an analog input
    WPUAbits.WPUA4 = 0;     // Disable weak pull-up on pin 3

    TRISAbits.TRISA2 = 1;   // Set pin 11 as an input for Temperature Sensor
    ANSELAbits.ANSA2 = 1;   // Set pin 11 as an analog input
    WPUAbits.WPUA2 = 0;     // Disable weak pull-up on pin 11

    APFCONbits.RXDTSEL = 0; // Set RX to RC5
    APFCONbits.TXCKSEL = 0; // Set TX to RC4
    BAUDCONbits.SCKP = 0;   // Transmit Non-Inverted Data on TX
    BAUDCONbits.BRG16 = 0;  // 8-bit Baud Rate Generator is used
    BAUDCONbits.ABDEN = 0;  // Auto-Baud Detect Mode Disabled
    SPBRGH = 25;            //
    SPBRGL = 25;            //

    TXSTAbits.TX9 = 0;      // 8 bit transmission
    TXSTAbits.TXEN = 1;     // Enable Transmiter
    TXSTAbits.SYNC = 0;     // Configure EUSART for asynchronous operation
    TXSTAbits.BRGH = 1;     // High speed baud rate select bit
    RCSTAbits.SPEN = 1;     // Enable Serial Port
    RCSTAbits.RX9 = 0;      // 8-bit Reception
    RCSTAbits.CREN = 1;     // Enable Receiver

    APFCONbits.SDOSEL = 0;  // Set SDO to RC2
    APFCONbits.SSSEL = 0;   // Set SS to RC3

    while(1){// Start While Loop of Constant Operation
        LATAbits.LATA5 = !LATAbits.LATA5;
        for (i=65; i<=90; i++){
            TXREG = i;
            
        while(!PIR1bits.TXIF){}
        }
        TXREG = 0x0a;
        while(!PIR1bits.TXIF){}
    } // End While Loop of Constant Operation
    return (EXIT_SUCCESS);
}

