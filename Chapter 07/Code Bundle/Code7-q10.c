int goo(int i, int j)
{
   int k = 0;
   if (j > 5) k = 3;
   if (i > 0)
   {
      k = 1;
      if (i > 5) k = 2;
      subgoo1(i, j, k);
   }
   subgoo2(i);
   return k;
}
