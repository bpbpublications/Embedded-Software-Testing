/* reduces the value at the specified address by one */
extern int reduce_by_one(int*);

/* increases the value at the specified address by one */
extern int increment_by_one(int*);

int *pDIO_memory = 0x4000;
int *pADC_memory = 0x8000;

/* Specification: do not change any address contents */
int main()
{
   if (*pDIO_memory > 0)
   {
      reduce_by_one(pDIO_memory);
   }
   if (*pADC_memory > 0)
   {
      increment_by_one(pDIO_memory);
   }
   return 0;
}
