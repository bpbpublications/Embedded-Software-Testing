uint16_t intsqrt(uint32_t uiInput)
{
   unsigned uiRoot = 0;
   unsigned uiRemHi = 0, uiRemLo = uiInput;
   unsigned uiTestDiv;
   int iBits;

   for(iBits = 0; iBits < 16; iBits++)
   {
      uiRemHi = (uiRemHi << 2) | (uiRemLo >> 30);
      uiRemLo <<= 2;
      uiRoot <<= 1;
      uiTestDiv = (uiRoot << 1) + 1;
      if (uiRemHi >= uiTestDiv)
      {
         uiRemHi -= uiTestDiv;
         uiRoot++;
      }
   }
