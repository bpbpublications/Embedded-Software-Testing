int flash_gets(char *pcBuf, int iBufSize, int nHandle)
{
   static int iCall = 0;
   int iRetVal;

   checkint(1, iBufSize > 19);

   switch (iCall)
   {
      case 0: /* return largest valid integer */
         strcpy(pcBuf, "2147483647\n");
         iRetVal = strlen(pcBuf);
         break;
      case 1: /* return smallest invalid integer */
         strcpy(pcBuf, "2147483648\n");
         iRetVal = strlen(pcBuf);
         break;
      
      /* ... */
 
      case 10: /* return smallest valid integer */
         iRetVal = 0;
         break;
   }
   iCall++;
   return iRetVal;
}
