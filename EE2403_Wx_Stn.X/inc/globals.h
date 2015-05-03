/* 
 * File:   globals.h
 * Author: Mike
 *
<<<<<<< HEAD
 * Created on February 25, 2015, 12:13 PM
=======
 * Created on April 8, 2015, 11:08 AM
>>>>>>> 25b9476703b708b4a18d91082ed150be80f59191
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

<<<<<<< HEAD
#ifdef	__cplusplus
extern "C" {
#endif

#include <Generic.h>

    typedef enum
    {
        PRESSTEMP = 0,
                GPS = 1,
                FREE = 2
    }_UBUFFER;

    extern _UBUFFER UARTBUFFER;

//extern DWORD_VAL Flags;






#ifdef	__cplusplus
}
#endif
=======
#include <string.h>
#include <Generic.h>

extern BYTE_VAL Flags;

#define ADREADY(x)      Flags.bits.b0 = (x)
#define DEF2            Flags.bits.b1
#define DEF3            Flags.bits.b2
#define DEF4            Flags.bits.b3
#define DEF5            Flags.bits.b4
#define DEF6            Flags.bits.b5
#define DEF7            Flags.bits.b6
#define DEF8            Flags.bits.b7


extern int ADRaw;
extern double ADValue,ADAverage,ADTest;
//extern char U1RXDat[80];



>>>>>>> 25b9476703b708b4a18d91082ed150be80f59191

#endif	/* GLOBALS_H */

