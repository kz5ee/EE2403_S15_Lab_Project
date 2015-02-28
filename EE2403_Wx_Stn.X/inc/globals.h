/* 
 * File:   globals.h
 * Author: Mike
 *
 * Created on February 27, 2015, 5:50 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Generic.h>

    extern DWORD_VAL Flags;


#define SHOWUI              Flags.byteUnion.lowLSB.bits.b0
#define FLAGDEF2            Flags.byteUnion.lowLSB.bits.b1
#define FLAGDEF3            Flags.byteUnion.lowLSB.bits.b2
#define FLAGDEF4            Flags.byteUnion.lowLSB.bits.b3
#define FLAGDEF5            Flags.byteUnion.lowLSB.bits.b4
#define FLAGDEF6            Flags.byteUnion.lowLSB.bits.b5
#define FLAGDEF7            Flags.byteUnion.lowLSB.bits.b6
#define FLAGDEF8            Flags.byteUnion.lowLSB.bits.b7

    extern void InitGlobals(void);

    typedef enum{
        ENABLED = 1,
                DISABLED =0
    }_UISTATE;

    extern _UISTATE UI;
    



#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

