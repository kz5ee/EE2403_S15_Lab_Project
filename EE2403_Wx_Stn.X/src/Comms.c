#include <stdio.h>
#include <p24Exxxx.h>
#include <pps.h>
#include "../inc/Comms.h"


//<editor-fold defaultstate="collapsed" desc="UART Configuration">
void UART1_Config(void){

    OpenUART1((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART1_ //Baud rate
            ));
    ConfigIntUART1(
                UART_RX_INT_EN &        //Receive interrupt enabled
                UART_RX_INT_PR4 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR2         //Priority TX interrupt 1
            );



    
    TRISFbits.TRISF4 = 1;               //Set UART1 RX as input
    TRISFbits.TRISF5 = 0;               //Set UART1 TX as output

    PPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP100);
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP101);

    printf("UART1 Configured.\r\n");
}

#ifdef _U2RXIF
void UART2_Config(void){

    OpenUART2((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART2_ //Baud rate
            ));
    ConfigIntUART2(
                UART_RX_INT_EN &        //Receive interrupt enabled
                UART_RX_INT_PR1 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR2         //Priority TX interrupt 1
            );

    TRISFbits.TRISF2 = 1;               //Set UART2 RX as input
    TRISFbits.TRISF8 = 0;               //Set UART2 TX as output

    PPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP98);
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP104);

    printf("UART2 Configured.\r\n");
}
#endif

#ifdef _U3RXIF
void UART3_Config(void){

    OpenUART3((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART3_ //Baud rate
            ));
    ConfigIntUART3(
                UART_RX_INT_EN &        //Receive interrupt enabled
                UART_RX_INT_PR1 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR2         //Priority TX interrupt 1
            );

    printf("UART3 Configured.\r\n");
}
#endif

#ifdef _U4RXIF
void UART4_Config(void){

    OpenUART4((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART4_ //Baud rate
            ));
    ConfigIntUART4(
                UART_RX_INT_EN &        //Receive interrupt enabled
                UART_RX_INT_PR1 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR2         //Priority TX interrupt 1
            );

    printf("UART4 Configured.\r\n");
}
#endif
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="SPI Configuration">
   void SPI1_Config(void)
    {
        IFS0bits.SPI1IF = 0; // Clear the Interrupt flag
        IEC0bits.SPI1IE = 0; // Disable the interrupt

        // SPI setup code for pic24EP512GU810
        SPI1STATbits.SPIEN = 1;         // Enable SPI 1
        SPI1STATbits.SPISIDL=0;         // Operate during IDLE mode
        SPI1STATbits.SPIEN = 0;         // Enable SPI 1 after setup

        SPI1CON1bits.DISSCK = 0;	// SPIx clock on SCKx pin is enabled
        SPI1CON1bits.DISSDO = 0;	// SDOx pin is controlled by the module
        SPI1CON1bits.MODE16 = 0;	// Communication is byte-wide (8 bits)
        SPI1CON1bits.SMP = 0;           // Input data is sampled at the middle of data output time
        SPI1CON1bits.CKE =	1;	// Serial output data changes on transition from active clock state to Idle clock state
        SPI1CON1bits.SSEN = 0;          // SSx pin is not used by the module; pin is controlled by port function
        SPI1CON1bits.CKP =	0;	// Idle state for clock is a low level; active state is a high level
        SPI1CON1bits.MSTEN = 1;         // Master mode
        SPI1CON1bits.SPRE = 0b110;	// Secondary prescale 2:1
        SPI1CON1bits.PPRE= 0b11;	// Primary prescale 1:1

        SPI1CON2bits.FRMEN = 0;         // Framed SPIx support is disabled
        SPI1CON2bits.SPIFSD = 0;	// Frame sync pulse output (master)
        SPI1CON2bits.FRMPOL = 0;	// Frame sync pulse is active-low
        SPI1CON2bits.FRMDLY = 0;	// Frame sync pulse precedes the first bit clock
        SPI1CON2bits.SPIBEN = 0;	// Enhanced buffer is disabled (Legacy mode)
    }
///</editor-fold>

//<editor-fold defaultstate="collapsed" desc="I2C Configuration">

//</editor-fold>

int anprintf(const char *format,...)
{
    char wireless_buff[80];
    int i = 0;
    va_list arguments;
    va_start( arguments, format );

    vsprintf(wireless_buff, format, arguments);

    do
    {
        while(!SPI1STATbits.SPITBF)
        SPI1BUF = wireless_buff[i];  //Send a character to the wireless module
        wireless_buff[i] = SPI1BUF;  //Read character sent from wireless module
        i++;
    } while(wireless_buff[i] != '\0');


    return 0;  //Success!
}