/* Supplementing material for the book Testing Embedded Software by Stephan Gruenfelder
 * and Adam Mackay. The authors welcome your feedback on the book and this sample code.
 * Feel free to contact us via stephan.gruenfelder@gmx.at.
 * This file mimics the flash memory with the help of stubs. For the 
 * purpose of unit testing (component testing) we do not need to access 
 * the real hardware. In an integration test step we could exchange this 
 * implementation here with the true one. */

#include <stdio.h>
#include <stdbool.h>
#include "Code7-2a.h"  /* Framework header*/

static FILE *f;
static int sessionHandle = 42;
static bool can_be_opened = true;
static bool opened = false;

bool flash_open(void)
{
	MY_ASSERT(!opened);
	f = fopen("flash_input.txt", "a+");
	opened = can_be_opened;
	return can_be_opened;
}

char* flash_gets(char* pcBuffer, int iBufSize)
{
	return fgets(pcBuffer, iBufSize, f);
}

int flash_write(char* pcBuffer)
{
	return fprintf(f, "%s", pcBuffer);
}

void flash_close()
{
	MY_ASSERT(opened);
	fclose(f);
	opened = false;
}

void flash_erase()
{
	f = fopen("flash_input.txt", "w+");
	fclose(f);
}

void simulate_defective_flash()
{
	can_be_opened = false;
}