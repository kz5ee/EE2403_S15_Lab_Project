/* 
 * File:   temp_press.h
 * Author: Mike
 *
 * Created on May 10, 2015, 3:28 PM
 */

#ifndef TEMP_PRESS_H
#define	TEMP_PRESS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Generic.h>
    
    extern char TPString[16];
    extern char *TPTokens[10];
    extern double Pressure, Temperature;

    extern void ParseTP(char **);
    extern UINT8 TokenizeTP(char *, char **);



#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_PRESS_H */

