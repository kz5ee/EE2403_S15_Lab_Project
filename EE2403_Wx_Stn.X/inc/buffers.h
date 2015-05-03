/* 
 * File:   buffers.h
 * Author: Mike
 *
 * Created on February 15, 2015, 6:25 PM
 */

#ifndef BUFFERS_H
#define	BUFFERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Generic.h>
#include "../inc/types.h"

#define TPBUFMAXSIZE            64
#define GPSBUFMAXSIZE           80
#define MAXRINGBUFSIZE          32

extern UINT8 UartRingBuffer[GPSBUFMAXSIZE];

extern void RngAdd(UINT8);
extern S16 RngGet(UINT16 *);
extern UINT16 RngDataUsed(UINT16*);


#ifdef	__cplusplus
}
#endif

#endif	/* BUFFERS_H */

