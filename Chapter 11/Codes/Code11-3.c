#include <rtos.h>
#include <stdio.h>

void philosopher1(void);  /* Thread 1 */
void philosopher2(void);  /* Thread 2 */

rtos_id id_fork1, id_fork2, id_thread1, id_thread2;

/* Dining Philosophers Problem */
int main(void)
{
   rtos_id id_thread1, id_thread2;

   rtos_lock_create(UNLOCKED, &id_fork1);
   rtos_lock_create(UNLOCKED, &id_fork2);
   rtos_thread_create(ROUND_ROBIN_SCHEDULING, &id_thread1);
   rtos_thread_create(ROUND_ROBIN_SCHEDULING, &id_thread2);

   rtos_thread_start(id_thread1, philosopher1);
   rtos_thread_start(id_thread2, philosopher2);

   return 0;
}

void philosopher1(void)
{
   rtos_lock(id_fork1);
   rtos_lock(id_fork2);
   /* critical section */
   rtos_unlock(id_fork2);
   rtos_unlock(id_fork1);
}

void philosopher2(void)
{
   rtos_lock(id_fork2);
   rtos_lock(id_fork1);
   /* critical section */
   rtos_unlock(id_fork1);
   rtos_unlock(id_fork2);
}
