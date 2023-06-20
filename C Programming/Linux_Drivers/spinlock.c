/*
 * spinlock.c
 *
 *  Created on: Aug 16, 2018
 *      Author: prabhaka
 */


/*
 * 1. static creation of spin lock
 * 				DEFINE_SPINLOCK(etx_spinlock);
 * 2. dymanic creation of spin lock
 * 				spinlock_t myspin;
 * 				spin_lock_init(&myspin);
 * 3. between kernel threds
 * 				1. spin_lock()
 * 				2. spin_trylock()
 * 				3. spin_unlock()
 * 				4. spin_is_locked()
 * 4. locking between bottom hal
 * 				1. spin_lock_bh()
 * 				2. spin_unlock_bh()
 * 5. locking in irq
 * 				1. sping_lock_irq()
 * 				2. spin_unlock_irq()
 *
 * 	6. sharing between two irq's
 * 				1. spin_lock_irqsave
 * 				2. spin_unlock_irqrestore
 * */
