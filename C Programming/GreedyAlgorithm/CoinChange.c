/*
 * CoinChange.c
 *
 *  Created on: 21-Jul-2017
 *      Author: sansaras
 */
#include<stdio.h>

typedef struct coin
{
int val;
int count;
}Coins;

Coins * getCoinCount(char *input, int number, int *output)
{
	Coins *coin = malloc();
	int i = 0;
	int count = 0;
	while(number != 0)
	{

		if(number <= input[i])
		{
			count = number % input[i];
			number = number / input[i];


		}
		i++;
	}


}

