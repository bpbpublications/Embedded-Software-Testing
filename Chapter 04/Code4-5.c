/* C-Program */

int Hoo();                      /* 1, incomplete prototype */
char cUartData = (char) 0xFA; 

main()
{ 
   unsigned uiA = 12;           /* 2, uiA is never used */
   int i, a[10] = {0,0,0,0,0,0,0,0,0,0}; /* 3, wrong number of initializers */

   for (i = 0; i <= 10; i++) 
   {
      a[i] += i;                /* 4, index exceeds buffer size */
   }
   for (i = 0; i <= 3; i++);    /* 5, suspicious semicolon */
   {
      a[i] = (int) Hoo;         /* 6, strange cast */
      a[i] -= cUartData; 
      a[i] += Hoo(); 
   }
}                               /* 7, no return value of main */

int Hoo(int x)
{
   return x + 2;
}
