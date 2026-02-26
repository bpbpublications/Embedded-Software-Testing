int to_be_tested(int x)
{
   do
   {
      /* here x is not manipulated and never branches */
   } while (x == 0);
   return -42; 
}
