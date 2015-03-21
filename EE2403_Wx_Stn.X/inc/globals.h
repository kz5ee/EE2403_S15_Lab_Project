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

#endif	/* GLOBALS_H */

