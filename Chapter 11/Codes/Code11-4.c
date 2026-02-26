if (shared_var == expected_value) /* no lock to be fast */ 
{
   /* unlikely case: now use the lock for read-modify-write */
   RTOS_Lock(mtx_for_shared_var);
   if (shared_var == expected_value) 
   {
      shared_var = foo(shared_var);
   }
   RTOS_Unlock(mtx_for_shared_var);
}
