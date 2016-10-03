#ifndef DEF_PIPLOCK_H
#define DEF_PIPLOCK_H

typedef volatile int pip_spinlock_t;

int pip_cas(pip_spinlock_t *addr, int ov, int nv);
void pip_spin_lock(pip_spinlock_t*lock);
int pip_spin_trylock(pip_spinlock_t *lock);
void pip_spin_unlock(pip_spinlock_t*lock);

#endif
