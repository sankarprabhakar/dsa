/*
 * ways_to_climp_steps.c
 *
 *  Created on: Aug 25, 2016
 *      Author: sankarsa
 */



/*
 * 1. There are 100 steps.
 * 2. A person a climb 1 step at a time or 2 step at a time.
 * 3. How many ways a person can climb 100 steps.
 *
 *  An example with 3 steps:
 *  	- (1,1,1), (1,2), (2,1).
 *
 * */

#define STEP_COUNT 10
unsigned int num_ways[STEP_COUNT+1] = {0,0};

void main_way(int argc, char*argv[])
{
	num_ways[1] = 1;
	num_ways[2] = 2;
	int i = 0;
	for(i = 3; i <= STEP_COUNT ; i++)
	{
		num_ways[i] = num_ways[i-1] + num_ways[i-2];
	//	printf("%u \n",num_ways[i]);
	}

	printf("%u \n", num_ways[i-1]);
}


