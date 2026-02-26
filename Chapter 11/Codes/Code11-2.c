#include <rtos.h>
#include <stdio.h>

extern int is_prime(int);

void counter1(void);  /* Thread 1 */
void counter2(void);  /* Thread 2 */

int primes = 0, rtos_id, id_lock, id_thread1, id_thread2;

int main(void)
{
   rtos_lock_create(UNLOCKED, &id_lock);

   rtos_thread_create(ROUND_ROBIN_SCHEDULING, &id_thread1);
   rtos_thread_create(ROUND_ROBIN_SCHEDULING, &id_thread2);
   rtos_thread_start(id_thread1, counter1);
   rtos_thread_start(id_thread2, counter2);

   printf("There are %d prime numbers between 1 and 20000", primes);
   return 0;
}

void counter1(void)
{
   int i;
   for (i = 1; i < 10000; i++)
   {
      if (is_prime(i)) 
      {
         rtos_lock(id_lock);
         primes = primes + 1;
         rtos_unlock(id_lock);
      }
   }
}

void counter2(void)
{
   int i;
   for (i = 10000; i < 20000; i++)
   {
      if (is_prime(i)) 
      {
         rtos_lock(id_lock);
         primes++;
         rtos_unlock(id_lock);
      }
   }
}
