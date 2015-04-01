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

int i=0;            //Counting Variable
int PressureH;      // Pressure high byte Sensor Reading
int PressureL;      // Pressure low byte
int TemperatureH;   // Temperature high byte Sensor Reading
int TemperatureL;   // Temperature low byte
int Pressure;       // Converted Pressure
int Temperature;    // Converted Temperature
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
    TRISCbits.TRISC5 = 1;   // Set pin 5 as an input for UART

    APFCONbits.TXCKSEL = 0; // Set TX to RC4
    TRISCbits.TRISC4 = 0;   // Set pin 6 as an output for UART

    BAUDCONbits.SCKP = 0;   // Transmit Non-Inverted Data on TX
    BAUDCONbits.BRG16 = 0;  // 8-bit Baud Rate Generator is used
    BAUDCONbits.ABDEN = 0;  // Auto-Baud Detect Mode Disabled
    SPBRGH = 25;            //
    SPBRGL = 25;            //

    TXSTAbits.TX9 = 0;      // 8 bit transmission
    TXSTAbits.TXEN = 1;     // Enable Transmiter
    TXSTAbits.SYNC = 0;     // Configure EUSART for asynchronous operation
    TXSTAbits.BRGH = 1;     // High speed baud rate select bit
    RCSTAbits.SPEN = 1;     // Enable Receiver
    RCSTAbits.RX9 = 0;      // 8-bit Reception
    RCSTAbits.CREN = 1;     // Enable Receiver

    APFCONbits.SDOSEL = 0;  // Set SDO to RC2
    APFCONbits.SSSEL = 0;   // Set SS to RC3

    // Configure ADC
    ADCON0bits.ADON = 0;    // Disable AD module during setup
    ADCON1bits.ADPREF = 0;  // Vref = VDD
    ADCON1bits.ADCS = 0b100;// A/D Conversion Clock Fosc/4
    ADCON1bits.ADFM = 0;    // Left Justify Conversion starts at High bit 7 until low bit 6
    PIE1bits.ADIE = 0;      // Disable AD interrupt
    ADCON0bits.ADON = 1;    // Enable AD module after setup


    while(1){// Start While Loop of Constant Operation
        LATAbits.LATA5 = !LATAbits.LATA5;
        
        // Test UART
        /*
         *  for (i=65; i<=90; i++){
         *      TXREG = i;                  // Step Through Alphabet
         *      while(!PIR1bits.TXIF){}}    // Wait for Buffer to Clear
         *  TXREG = 0x0a;               // New Line
         *  while(!PIR1bits.TXIF){}     // Wait for Buffer to Clear
         */

        // Check for request from UART
            // Check RX flag for something in the buffer
                while(!RCIF){}  // If nothing in the FIFO, wait longer
        
        if(RCREG == 13){ // Begin Conversion/Transmission Loop
            // Convert Pressure and Temperature, then transmit results
            // ADC on Pressure
                ADCON0bits.CHS = 0b00011;       // Set channel for pressure sensor input
                ADCON0bits.GO = 1;              // Start a conversion
                while(ADCON0bits.GO){}          // Wait for conversion to complete
                PressureH = ADRESH;             // Move High Address of conversion to PressureH
                PressureL = ADRESL;             // Move Low Address of conversion to PressureL
            // Convert Pressure
                Pressure = 0;                   // Lookup Table or Mathematical Conversion of Reading
            // ADC on Temperature
                ADCON0bits.CHS = 0b00010;       // Set channel for temperature sensor input
                ADCON0bits.GO = 1;              // Start a conversion
                while(ADCON0bits.GO){}          // Wait for conversion to complete
                TemperatureH = ADRESH;          // Move High Address of conversion to TemperatureH
                TemperatureL = ADRESL;          // Move Low Address of conversion to TemperatureL
            // Convert Temperature
                Temperature = 0;                // Lookup Table or Mathematical Conversion of Reading
            // Transmit Resultsin format *TP,Temperature,Pressure,$  LSB first
                TXREG = 0x2A;                   // Transmit *
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = 0x54;                   // Transmit T
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = 0x50;                   // Transmit P
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = 0x2C;                   // Transmit ,
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = Temperature;            // Transmit Temperature
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = 0x2C;                   // Transmit ,
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = Pressure;               // Transmit Pressure
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = 0x2C;                   // Transmit ,
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
                TXREG = 0x24;                   // Transmit $
                while(!PIR1bits.TXIF){}         // Wait for Buffer to Clear
        }   // End Conversion/Transmission Loop
    } // End While Loop of Constant Operation
    return (EXIT_SUCCESS);
}

