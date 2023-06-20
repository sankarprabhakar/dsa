/*
 * longest_increasing_subsequence.c
 *
 *  Created on: Dec 21, 2016
 *      Author: sankarsa
 */


int find_lis(int *v, int s)
{

	int *lis = malloc(s*sizeof(int));
	int i = 0, j = 0;
	int max = -1;
	lis[0] = 1; //init the lis
	for(i = 1; i<s; i++)
	{
		max = 0;
		for(j = 0; j<=i; j++)
		{
			if(v[i] > v[j])
			{
				max = max < lis[j]?lis[j]:max;
			}
		}
		lis[i] = 1 + max;
	}
	max = 0;
	for(i = 0 ; i < s ; i++)
	{
		max = max < lis[i]?lis[i]:max;
	}
	return max;

}
