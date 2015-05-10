


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/buffers.h"
#include "../inc/globals.h"


UINT8 UartRingBuffer[GPSBUFMAXSIZE];//Max length of NEMA sentence is 80 and the max STX is 154

UINT16 HIndex = 0,TIndex = 0;//Internal Indexes

/// @fn void RngAdd(U8 NewData)
/// @author Jonathan Streeter
/// @date 1/20/2014
/// @brief Adds to the Buffer and moves the Head and Tail
/// @details Adds a new data byte from the UART interrupt to the Ring Buffer and
///	moves the Head and Tail buffer. This is the ONLY function that
///	moves the Head Pointer
///
/// @param NewData Data to be inserted into the RngBuffer
/// @return void
////////////////////////////////////////////////////////////////////////////////
void RngAdd(UINT8 NewData)
{
    
        UartRingBuffer[HIndex] = NewData;//Shove data in
        HIndex =(HIndex + 1) % GPSBUFMAXSIZE;//Advance and check overflow
        if(HIndex == TIndex)//Check if they have looped back on eachother
          TIndex =(TIndex + 1) % GPSBUFMAXSIZE;//If so andvance the TP
        
}

/// @fn S16 RngGet(U8 *LocalTailIndex)
/// @author Jonathan Streeter
/// @date 1/21/2014
/// @brief Adds to the Buffer and moves the Head and Tail
/// @details Get the next char from the ring buffer using the Local Tail Index that you pass it.
///	If the return is > 0xFF then the Tail is at the Head. The Tail index is moved to
///	the next char
/// @param LocalTailIndex
/// @return char that it pulled. EOF if the Head matches the tail
////////////////////////////////////////////////////////////////////////////////

S16 RngGet(volatile UINT16 *LocalTailIndex)
{
S16 RTV = EOF;

    if(*LocalTailIndex != HIndex)//Not Matching
    {
        RTV = UartRingBuffer[ *LocalTailIndex ];//Grab data
        *LocalTailIndex =(*LocalTailIndex + 1) % GPSBUFMAXSIZE;//increment and check for overflow
    }

    return(RTV);//Will be 0xFFFF if no new char was aquired
}

/// @fn U8 RngDataUsed(U8* LocalTailIndexPeek)
/// @author Jonathan Streeter
/// @date 1/21/2014
/// @brief Using local TailIndex return howmany bytes ahead the Head is.
/// @details Using local TailIndex return howmany bytes ahead the Head is.
///
/// @param LocalTailIndexPeek The index that is passed in
/// @return Number of bytes left in Buffer
////////////////////////////////////////////////////////////////////////////////
UINT16 RngDataUsed(UINT16* LocalTailIndexPeek)
{
    UINT16 DataLeft = 0;
    UINT16 Temp = HIndex;

    if(Temp < *LocalTailIndexPeek)
    Temp += GPSBUFMAXSIZE;

    DataLeft = (UINT16) (Temp - *LocalTailIndexPeek);

    return(DataLeft);
}