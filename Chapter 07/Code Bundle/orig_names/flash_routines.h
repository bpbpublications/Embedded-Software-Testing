/* FLash routines - this could and should be the original header file */

/* open a session */
bool flash_open(void);

/* read from the flash, smantics like gets() */
char* flash_gets(char* pcBuffer, int iBufSize);

/* read write to the flash, smantics like printf */
int flash_write(char* pcBuffer);

/* end a session */
int flash_close();

/* delete entire flash content */
void flash_erase();


