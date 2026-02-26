/* C Programming Language */

#include <string.h>

char* MyName();
char cUartData = (char) 0xFA;

main()
{
   unsigned uiA = (unsigned) cUartData;
   int i, a[10] = {0,0,0,0,0,0,0,0,0};

for (i = 0; i <= 10; i++)
   {
      a[i] += i;
   }
   for (i = 0; i <= 3; i++);
   {
      char szString[10];
      a[i] -= cUartData;
      strcpy(szString, MyName());
   }
}

char* MyName(int i)
{
   char name[11] = "Joe Jakeson";
   if (i) name[2] = 'i';
   return name;
}
