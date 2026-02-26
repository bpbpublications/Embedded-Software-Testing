unsigned short intsqrt(unsigned uiInput)
{
   unsigned short hiRoot = 0;
   unsigned short uiRemHi = 0, uiRemLo = uiInput;
   unsigned short uiTestDiv;
   short iBits;

   for(iBits = 0; iBits < 16; iBits++)
   {
      uiRemHi = (uiRemHi << 2) | (uiRemLo >> 30);
      uiRemLo <<= 2;
      hiRoot <<= 1;
      uiTestDiv = (hiRoot << 1) + 1;
      if (uiRemHi >= uiTestDiv)
      {
         uiRemHi -= uiTestDiv;
         hiRoot++;
      }
   }
   return hiRoot;
}
