void malicious_subroutine()
{
   int a[10000]; /* Larger than the entire stack */
   a[9999] = 42; /* Unrecognized destruction */
}
