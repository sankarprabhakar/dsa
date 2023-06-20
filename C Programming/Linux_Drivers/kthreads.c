/*
 * kthreads.c
 *
 *  Created on: Aug 17, 2018
 *      Author: prabhaka
 */


/*
 *
 *  1.A thread is a sequence of instructions.
    2.CPU can handle one instruction at a time.
    3.To switch between instructions on parallel threads, execution state need to be saved.
    4.Execution state in its simplest form is a program counter and CPU registers.
    5.Program counter tells us what instruction to execute next.
    6.CPU registers hold execution arguments for example addition operands.
    7.This alternation between threads requires management.
    8.Management includes saving state, restoring state, deciding what thread to pick next.

creation:
struct task_struct * kthread_create (int (* threadfn(void *data),  void *data, const char namefmt[], ...);

deletion:
int wake_up_process (struct task_struct * p);


kthread_run (threadfn, data, namefmt, ...); - Creates and run the kthread, it is replacement of above two
functions

int kthread_stop ( struct task_struct *k);
int kthread_should_stop (void);


void kthread_bind (struct task_struct *k, unsigned int cpu);



    */
