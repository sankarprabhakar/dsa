/*
 * time_nanosleep.c
 *
 *  Created on: Jun 30, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include<time.h>

void main(int arg, char * argv[])
{
	printf("Going to sleep \n");

	struct timespec x,y;
	x.tv_sec = 100;
	x.tv_nsec = 100;
	nanosleep(&x,&y);
	printf("%lu - %lu\n", y.tv_sec, y.tv_nsec);

}
