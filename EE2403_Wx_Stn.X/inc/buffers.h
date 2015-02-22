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

#define MAXRINGBUFSIZE      64


typedef enum
{
    Good = 0,
            BufferFull
}BuffStatus;

extern BuffStatus AddtoBuffer(char);
extern char ReadfromBuffer(void);
extern int FreeSpace(void);
extern void ShowBuffer(void);
extern void InitBuffer(void);
extern void ClearBuffer(void);


extern char buffer[];
#define FIRST_POINTER   &buffer[0]
#define LAST_POINTER    &buffer[MAX_BUFFER-1]

extern char *head;
extern char *tail;

#ifdef	__cplusplus
}
#endif

#endif	/* BUFFERS_H */

