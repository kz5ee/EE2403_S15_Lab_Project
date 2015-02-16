


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/buffers.h"

char *head;
char *tail;
char buffer[MAX_BUFFER];

BuffStatus AddtoBuffer(char character)
{
    BuffStatus rv = Good;  //rv = return value
    char *tailfromhead;
    tailfromhead = tail;

    if (++tailfromhead > LAST_POINTER)
    {
        tailfromhead = FIRST_POINTER;
    }
    if (++tailfromhead == head)
    {
        rv = BufferFull;
        return 1;
    }

    *tail = character;

    if (++tail > LAST_POINTER)
    {
        tail = FIRST_POINTER;
    }

    return 0;
}

char ReadfromBuffer(void)
{
    char rv;  //rv = Return Value

    if (head == tail)
    {
        return '\0';
    }

    rv = *head;

    if (++head > LAST_POINTER)
    {
        head = FIRST_POINTER;
    }

    return rv;
}

int FreeSpace(void)
{
    if(tail == head)
    {
        return (MAX_BUFFER - 1);
    }

    if(tail > head)
    {
        return ((MAX_BUFFER - 1) - (tail - head));
    }


    return ((MAX_BUFFER - 1) - (tail - FIRST_POINTER) - (LAST_POINTER - head));
}

void ClearBuffer(void)
{
    tail = head;
    return;
}
//void ShowBuffer(void)
//{
//    //@showbuffer
//    int i;
//
//    printf("Current buffer:  \n");
//    for (i=0; i < MAX_BUFFER; i++)
//    {
//        printf("%c: ", buffer[i]);
//    }
//    printf("\n:");
//
//    return;
//}

void InitBuffer(void)
{
    int i;

//    for(i = 0; i < MAX_BUFFER; i++)
//    {
//        buffer[i] = '1';
//    }

    memset(buffer, '\0', sizeof(buffer));

    head = &buffer[0];
    tail = &buffer[0];

    return;
}
