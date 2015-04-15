/* 
 * File:   globals.h
 * Author: Mike
 *
 * Created on April 8, 2015, 11:08 AM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

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
extern double ADValue,ADAverage;
//extern char U1RXDat[80];




#endif	/* GLOBALS_H */

