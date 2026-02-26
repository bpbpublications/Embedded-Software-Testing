lock(L1);
lock(L2);
unlock(L2);
lock(L3);
unlock(L3);
unlock(L1);
Thread 2:
lock(L1);
lock(L2);
unlock(L1);
unlock(L2);
