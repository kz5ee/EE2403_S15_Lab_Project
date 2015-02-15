/* 
 * File:   io_conf.h
 * Author: Mike
 *
 * Created on February 15, 2015, 4:11 PM
 */

#ifndef IO_CONF_H
#define	IO_CONF_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <p24Exxxx.h>
#include <pps.h>

    extern void ANSELA_Config(void);

    extern void EXTINT_Config(void);

    extern void TRIS_Config(void);

    extern void PPS_Config(void);

#ifdef	__cplusplus
}
#endif

#endif	/* IO_CONF_H */

