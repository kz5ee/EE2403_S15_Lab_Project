/* 
 * File:   globals.h
 * Author: Mike
 *
 * Created on February 25, 2015, 12:13 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Generic.h>

extern DWORD_VAL Flags;

#define U2RXBUFF    Flags.wordUnion.low.bits.b0
#define U3RXBUFF    Flags.wordUnion.low.bits.b1
#define U4RXBUFF    Flags.wordUnion.low.bits.b2




#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

