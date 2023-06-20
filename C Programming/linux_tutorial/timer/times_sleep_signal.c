/*
 * times_sleep.c
 *
 *  Created on: Jun 30, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<signal.h>

#include<time.h>
void interrupt_alarm(int sig)
{
	printf("3 secs overs\n");
	//fflush(stdout);
	alarm(1);
}
void main(int argc, char* argv[])
{
	signal(SIGALRM,interrupt_alarm);
	//alarm(3);
	sigset_t new, old;
	sigfillset(&new);
	sigdelset(&new, SIGALRM);
	sigprocmask(SIG_BLOCK, &new,&old);
	/*All are masked expect SIGALRM, as sigsuspend is used in infinite loop. This will avoid
	 default handling of signal after handling  signal.. Sigsuspend will resume the mask while returning*/

#if 1
	while(1)
	{

		sigsuspend(&new);//All signal expect SIGALARM needs masking as it is used in loop.

//		pause(); //this also works same way as other signals are blocks...




		;//	printf("3 secs overs");

	}
#endif
}



