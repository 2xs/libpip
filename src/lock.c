#include <pip/lock.h>

int pip_cas(pip_spinlock_t *addr, int ov, int nv)
{
	__asm__("lock cmpxchg %2, %1"
			: "=a"(ov)
			: "m"(*addr), "r"(nv), "a"(ov)
			: "memory");
	return ov;
}

void pip_spin_lock(pip_spinlock_t *lock)
{
	while (pip_cas(lock, 0, 1) != 0);
}

int pip_spin_trylock(pip_spinlock_t *lock)
{
	return pip_cas(lock, 0, 1);
}

void pip_spin_unlock(pip_spinlock_t*lock)
{
	*lock = 0;
}
