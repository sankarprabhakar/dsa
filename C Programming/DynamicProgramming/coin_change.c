/*
 * coin_change.c
 *
 *  Created on: Feb 13, 2018
 *      Author: prabhaka
 */

/*
 *  1. Given an array that contains the coins
 *  	eg {1,2,3}
 *  2. Find the number of ways to given change for amount n
 *  3. For example when 4 is given
 *  	{1,1,1,1}, {1,1,2}, {1,3}}, {2,2} - 4 ways.
 *
 * */

test_coin_main()
{
	 int array[] = {1,2,3};
	 int ways = countWays(array,3,4);

	 //printf("ways = %d \n", ways);
	 ways = countWaysDp(array, 3,4);
	 printf("ways = %d \n", ways);
}

int countWays(int array[], int n, int sum)
{
	 if(sum ==0) //we found a solution
		 return 1;
	 if(sum < 0) //no further
		 return 0;
	 if(sum > 0 && n <= 0)
	 {
		 return 0;
	 }
	 return countWays(array, n-1, sum) + countWays(array, n, sum - array[n-1]);/* why n is not (n-1)?,  bcs
	 we have inifinite number of coin*/
}


int countWaysDp(int C[],int n, int sum)
{
	int *m = malloc((sum+1) * (n) * sizeof(int));
	int (*p)[sum+1];
	p = m;
	for(int i = 0 ; i < n ; i++)
		p[i][0] = 1;
	for(int i = 1 ; i <= sum ; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			int x = (i - C[j]) >= 0 ? p[j][i-C[j]]:0;
			int y =  (j >= 1)?p[j-1][i]:0;
			p[i][j] = x + y;
		}
	}
	return p[n-1][sum];
}
