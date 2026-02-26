#include <rtos.h>
#include <stdio.h>
extern int is_prime(int);

void counter1(void);  /* Thread 1 */
void counter2(void);  /* Thread 2 */

int primes = 0; /* so many prime numbers have been found */
rtos_id id_thread1, id_thread2;

int main(void)
{
   rtos_thread_create(ROUND_ROBIN_SCHEDULING, &id_thread1);
   rtos_thread_create(ROUND_ROBIN_SCHEDULING, &id_thread2);

   /* start threads */
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
      if (is_prime(i)) primes = primes + 1;
   }
}

void counter2(void)
{
   int i;
   for (i = 10000; i < 20000; i++)
   {
      if (is_prime(i)) primes++;
      /* the ++ operator also does not guarantee atomicity of the increment */
   }
}
