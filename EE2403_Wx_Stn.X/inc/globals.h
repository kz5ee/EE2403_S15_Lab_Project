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

#include <string.h>
#include <Generic.h>

extern BYTE_VAL Flags;

#define GETCHECKSUM     Flags.bits.b0
#define PARSEGPSGGA     Flags.bits.b1
#define TPACQUIRED      Flags.bits.b2
#define GPSRDY          Flags.bits.b3
#define TPRDY           Flags.bits.b4
#define RDY2SND         Flags.bits.b5
#define DEF7            Flags.bits.b6
#define DEF8            Flags.bits.b7


extern int ADRaw;
extern double ADValue,ADAverage,ADTest;
extern void dtoa(double, char *);


#endif	/* GLOBALS_H */

