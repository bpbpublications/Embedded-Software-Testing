/* Supplementing material for the book Testing Embedded Software by Stephan Gruenfelder
 * and Adam Mackay. The authors welcome your feedback on the book and this sample code.
 * Feel free to contact us via stephan.gruenfelder@gmx.at.
 * This is the source file under test. It contains a single C-function.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Code7-1a.h"  /* Flash routines header*/

/* The specification of this function can be found in chapter 7 of the book. 
 * We see that the function has no arguments and no return value becaue the I/O 
 * of this function happens via flash-memory and file accesses. In consequence 
 * our test needs to prepare the flash content before the call of this function 
 * and also needs to check the result via file access. */
void file_sqrt()
{
    bool bOK = flash_open(); /* starts accessing the flash memory */

    if (bOK) /* only if the flash is accessible */
    {
        char szString[20]; /* string with termination character at the end */
        char szCheck[20];
        FILE* nOut = fopen("out.txt", "w+");

        while (flash_gets(szString, sizeof(szString)))
        {
            int i, number;
            bool ok = true;

            for (i = 0; i < strlen(szString) - 1; i++)
            {
                if (!isdigit(szString[i]))
                {
                    ok = false; /* not an int number */
                    break;
                }
            }
            if (!ok) continue; /* fail silently */
            
            number = atoi(szString);
            sprintf(szCheck, "%d", number);
            szString[strcspn(szString, "\n")] = '\0';
            if (strcmp(szCheck, szString) != 0)
            {
                continue; /* overflow, fail silently */
            }
            fprintf(nOut, "%d\n", (int)sqrt(atoi(szString)));
        } /* while we can read something from flash memory */

        fclose(nOut);
        (void)flash_close();
    } /* if flash is accessible */
}
