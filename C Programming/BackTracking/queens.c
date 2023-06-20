/*
 * queens.c
 *
 *  Created on: Jan 10, 2017
 *      Author: sankarsa
 */


#include<stdbool.h>
int x[5] = {0}; // 0 is not used


int main_queens()
{
	NQueens(1,4);
}
bool place(int k, int i); //k-row i - column

printQueenpos(int n)
{
	int i = 0, j = 0;
	for(i = 1; i <= n ; i++)
	{
		for(j = 1; j<= n; j++)
		{
			if(x[i] == j)
				printf("Q   ");
			else
				printf("*   ");
		}
		printf("\n");
	}
	printf("---------------\n");
}
NQueens(int k, int n)
{
	int j;
	for(j = 1; j<=n; j++)
	{
		if(place(k, j))
		{
			x[k] = j;
			if(k == n)
			{
				printQueenpos(n);
				//return;
			}
			else
				NQueens(k+1, n);

		}

	}
}

bool place(int k, int i) //k-row i - column
{
	int j = 1;
	for(j = 1; j < k ; j++) //from 1 to k-1 rows
	{
		if(x[j] == i || abs(x[j] - i) == abs(k-j))
		{
			return false;
		}
	}
	return true;
}
