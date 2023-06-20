/*
 * climbing_starecase.c
 *
 *  Created on: Jan 8, 2017
 *      Author: sankarsa
 */
/*
 * Davis has staircases "s" in his house and he likes to climb each staircase  1, 2,3 or steps at a time.
 *  Being a very precocious child, he wonders how many ways there are to reach the top of the staircase.
 *  Given the respective heights for each of the staircases in his house, find and print the number of ways
 *  he can climb each staircase on a new line.
 * */

#include<stdio.h>

void main_staircase()
{
	int no_of_staircase = 0;
	scanf("%d",&no_of_staircase);
	int i = 0;
	int steps_in_staircase[no_of_staircase];
	for(; i<no_of_staircase; i++)
	{
		scanf("%d", &steps_in_staircase[i]);

	}

	for(i = 0; i<no_of_staircase; i++)
	{
		int number_of_ways = CalcNoWays(steps_in_staircase[i]);
		printf("%d\n",number_of_ways);
	}

}
/* Ways to climp is sum of n[n-1] + n[n-2] + n[n-3]*/
CalcNoWays(int no_steps)
{
	int steps[no_steps + 1];
	int i = 0;
	steps[0] = 0;
	steps[1] = 1;
	steps[2] = 2;
	steps[3] = 4;
	if(no_steps == 1)
	{
		return steps[1];
	}
	else if(no_steps == 2)
	{
		return steps[2];
	}
	else if(no_steps == 3)
	{
		return steps[3];
	}
	else
	{
		for(i = 4 ; i<=no_steps; i++)
		{
			steps[i] = steps[i-1] + steps[i-2] + steps[i-3];
		}
	}
	return steps[no_steps];
}





