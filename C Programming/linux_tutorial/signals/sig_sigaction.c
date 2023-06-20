/*
 * sig_sigaction.c
 *
 *  Created on: Jun 29, 2016
 *      Author: sankarsa
 */


#include<signal.h>


void sig_int(int sig)
{
	printf("Signal interrupt is caught\n");
}

struct sigaction x;


void main(int argc, char*argv[])
{

	x.sa_handler = &sig_int;
	sigaction(SIGINT, &x, NULL);
	pause();//stops the process till i get a signal..
	printf("got some signal; so going to do something\n");
	 while(1)
	 {

	 }
}
