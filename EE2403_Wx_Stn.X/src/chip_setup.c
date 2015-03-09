

#include <stdio.h>
#include <pps.h>
#include "../inc/chip_setup.h"
#include "../inc/timers.h"
#include "../inc/Comms.h"
#include "../inc/io_conf.h"


//<editor-fold defaultstate="collapsed" desc="Timer Configuration">
inline void Timer1_Setup(void)
{
    OpenTimer1(
            T1_OFF &
            T1_IDLE_CON &
            T1_GATE_OFF &
            T1_PS_1_64 &
            T1_SYNC_EXT_OFF &
            T1_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer1(
            T1_INT_PRIOR_2 &
            T1_INT_ON
                    );


    printf("Timer 1 setup\r\n");
}

#ifdef _T2IF

inline void Timer2_Setup(void)
{
    OpenTimer2(
            T2_OFF &
            T2_IDLE_CON &
            T2_GATE_OFF &
            T2_PS_1_64 &
            T2_32BIT_MODE_OFF &
            T2_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer2(
            T2_INT_PRIOR_2 &
            T2_INT_ON
                    );


    printf("Timer 2 setup\r\n");
}

#endif

#ifdef _T3IF

inline void Timer3_Setup(void)
{
    OpenTimer3(
            T3_OFF &
            T3_IDLE_CON &
            T3_GATE_OFF &
            T3_PS_1_64 &
            T3_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer3(
            T3_INT_PRIOR_2 &
            T3_INT_ON
                    );


    printf("Timer 3 setup\r\n");
}

#endif

#ifdef _T4IF

inline void Timer4_Setup(void)
{
    OpenTimer4(
            T4_OFF &
            T4_IDLE_CON &
            T4_GATE_OFF &
            T4_PS_1_64 &
            T4_32BIT_MODE_OFF &
            T4_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer4(
            T4_INT_PRIOR_2 &
            T4_INT_ON
                    );


    printf("Timer 4 setup\r\n");
}

#endif

#ifdef _T5IF

inline void Timer5_Setup(void)
{
    OpenTimer5(
            T5_OFF &
            T5_IDLE_CON &
            T5_GATE_OFF &
            T5_PS_1_64 &
            T5_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer5(
            T5_INT_PRIOR_2 &
            T5_INT_ON
                    );


    printf("Timer 5 setup\r\n");
}

#endif

#ifdef _T6IF

inline void Timer6_Setup(void)
{
    OpenTimer6(
            T6_OFF &
            T6_IDLE_CON &
            T6_GATE_OFF &
            T6_PS_1_64 &
            T6_32BIT_MODE_OFF &
            T6_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer6(
            T6_INT_PRIOR_2 &
            T6_INT_ON
                    );


    printf("Timer 6 setup\r\n");
}

#endif

#ifdef _T7IF

inline void Timer7_Setup(void)
{
    OpenTimer7(
            T7_OFF &
            T7_IDLE_CON &
            T7_GATE_OFF &
            T7_PS_1_64 &
            T7_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer7(
            T7_INT_PRIOR_2 &
            T7_INT_ON
                    );


    printf("Timer 7 setup\r\n");
}

#endif

#ifdef _T8IF

inline void Timer8_Setup(void)
{
    OpenTimer8(
            T8_OFF &
            T8_IDLE_CON &
            T8_GATE_OFF &
            T8_PS_1_64 &
            T8_32BIT_MODE_OFF &
            T8_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer8(
            T8_INT_PRIOR_2 &
            T8_INT_ON
                    );


    printf("Timer 8 setup\r\n");
}

#endif

#ifdef _T9IF

inline void Timer9_Setup(void)
{
    OpenTimer9(
            T9_OFF &
            T9_IDLE_CON &
            T9_GATE_OFF &
            T9_PS_1_64 &
            T9_SOURCE_INT,
            60027); //for ~10 (9.98)ms period.

    ConfigIntTimer9(
            T9_INT_PRIOR_2 &
            T9_INT_ON
                    );


    printf("Timer 9 setup\r\n");
}

#endif

//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="I/O Configuration">

    void ANSEL_Config(void)
    {
        ANSELA = 0x0000;
        ANSELB = 0x0000;
        ANSELC = 0x0000;
        ANSELD = 0x0000;
        ANSELE = 0x0000;
        ANSELG = 0x0000;
    }

    void TRIS_Config(void)
    {
        TRISA = 0x0000;
        TRISB = 0x0000;
        TRISC = 0x0000;
        TRISD = 0x0000;
        TRISE = 0x0000;
        TRISF = 0x0000;
        TRISG = 0x0000;
    }

    void PPS_Config(void)
    {
        //Set up RX for UARTs
        PPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RPI49);
        PPSInput(IN_FN_PPS_U2RX, IN_PIN_PPS_RPI50);
        //PPSInput(IN_FN_PPS_U3RX, IN_PIN_PPS_RPI51);
        //PPSInput(IN_FN_PPS_U4RX, IN_PIN_PPS_RPI52);

        //Set up TX for UARTs
        PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP84);
        PPSOutput(OUT_FN_PPS_U2TX, OUT_PIN_PPS_RP82);
        //PPSOutput(OUT_FN_PPS_U3TX, OUT_PIN_PPS_RP80);
        //PPSOutput(OUT_FN_PPS_U4TX, OUT_PIN_PPS_RP71);
    }
//</editor-fold>

    inline void ChipInitialize(void)
    {
        ANSEL_Config();
        TRIS_Config();
        UART1_Config();
        UART2_Config();
        PPS_Config();
    }