#include <stdio.h>
#include <string.h>

#include "../inc/temp_press.h"

char TPString[16] = "\0";
double Pressure = 0.0, Temperature = 0.0;

UINT8 TokenizeTP(char *TPSentence, char **tok)
{
    UINT8 rtv, index, length;

	length = strlen(TPSentence);
	rtv = 0;
	if (length > 2)
	{
		tok[0] = TPSentence + 2;
		rtv = 1;
		for (index = 2; index < length; index++)
		{
			if (TPSentence[index] == ',')
			{						// If we find a delimiter, end this token string
				// and point to the beginning of the next one,
				// even if this points to another delimiter or the NULL terminator!!
				tok[rtv++] = &TPSentence[index + 1];
				TPSentence[index] = 0;	// This delimiter is now NULL terminator for the previous token.
			}

			// in the unlikely case that there is no data between the final delimiter
			// and the NULL terminator, the final entry will point to the NULL terminator
			// thus yielding a legal, empty string.
		}
	}

	tok[rtv] = NULL;				// Mark the end.

        //printf("%s\r\n",&token);
	return rtv;
}

void ParseTP(char **toks)
{
    int	TokenIndex;

	TokenIndex = 1;
	if (sscanf(toks[TokenIndex++],"%f",&Pressure) != 1) Pressure = 0.0;		// Pressure
	if (sscanf(toks[TokenIndex++],"%f",&Temperature) != 1) Temperature = 0.0;	// Temperature

        

	return;
}

