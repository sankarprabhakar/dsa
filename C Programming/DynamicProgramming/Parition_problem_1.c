/*
 * Parition_problem_1.c
 *
 *  Created on: Feb 6, 2018
 *      Author: prabhaka
 */

#include<stdio.h>

int  findPartition(int arr[], int n);
int isSubSet(int arr[], int n, int sum);

void partition_recursion_main()
{
	int arr[] = {1,1,2,3,8,111};
	//printf("output = %d \n", findPartition(arr,sizeof(arr)/sizeof(arr[0])));
	printf("output = %d \n", findPart(arr,sizeof(arr)/sizeof(arr[0])));

}


int  findPartition(int arr[], int n)
{
	int sum = 0;
	for(int i = 0; i < n ; i++)
	{
		sum += arr[i];
	}
	printf("sum = %d \n", sum);
	if(sum % 2 != 0)
	{
		return 0;
	}
	return isSubSet(arr, n , sum/2);
}

int isSubSet(int arr[], int n, int sum)
{
	if(0 == sum)
	{
		return 1;
	}
	if(0 == n && 0 != sum)
	{
		return 0;
	}

	if(sum < arr[n-1])
	{
		return isSubSet(arr, n-1, sum);
	}
	return isSubSet(arr, n-1, sum) || isSubSet(arr, n-1, sum - arr[n-1]);;
}



int  findPart(int arr[], int n)
{
	int sum = 0;
	for(int i = 0; i < n ; i++)
	{
		sum += arr[i];
	}
	printf("sum = %d \n", sum);
	if(sum % 2 != 0)
	{
		return 0;
	}
	return isPartitionPossible(arr, n , sum/2);
}

/*
 * P(i,j) = Max { P(i-1, j) or P(i-1, j-Ai)};
 *
 * */

int isPartitionPossible(int arr[], int n, int sum)
{
	int *partTab = (void *)malloc(sizeof(int) * (sum+1) * (n+1));
	int (*p)[sum+1];
    p = partTab;

	for(int i = 0; i <=n ; i++)
	{
		p[i][0] = 1;
	}
	for(int i = 1; i <=sum ; i++)
	{
			p[0][i] = 0;

	}

	for(int i = 1; i <=n ; i++)
	{
		for(int j = 1; j <=sum ; j++)
		{
			p[i][j] = p[i-1][j];
			if(j >= arr[i-1])
			{
				p[i][j] = p[i][j] || p[i-1][j-arr[i-1]];
			}
		}
	}

	for(int i = 0; i <=n ; i++)
		{
			for(int j = 0; j <=sum ; j++)
			{
				printf("%d \t", p[i][j]);
			}
			printf("\n");
		}


   return p[n][sum];
}


