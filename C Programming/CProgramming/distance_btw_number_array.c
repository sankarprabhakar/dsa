/*Program to find minimum distance between two given numbers in an array*/
/*
Input: arr[] = {1, 2}, x = 1, y = 2
Output: Minimum distance between 1 and 2 is 1.

Input: arr[] = {3, 4, 5}, x = 3, y = 5
Output: Minimum distance between 3 and 5 is 2.

Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
Output: Minimum distance between 3 and 6 is 4.

Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
Output: Minimum distance between 3 and 2 is 1.

*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int get_minimum_dist(int *arr,int n, int n1, int n2)
{
	int i= 0,j=0;int min_dist = INT_MAX;
	if(arr != NULL)
	{
		for(i = 0; i<n; i++)
		{
			for(j = i+1; j<n; j++)
			{
				if(((arr[i] == n1 && arr[j] == n2) || (arr[i] == n2 && arr[j] == n1)) &&\
					min_dist > abs(i-j))
				{
						min_dist = abs(j-i);

				}
			}
		}
	}
	return min_dist;
}



int get_minimum_dist1(int *arr, int n, int n1, int n2)
{
    int i = 0, prev=-1, min_dist = INT_MAX;
    if(arr != NULL)
    {
    	for(; i<n; i++)
    	{
    		if(arr[i] == n1 || arr[i] == n2)
    		{
    			if(prev == -1 || (arr[prev] == arr[i]))
    			{
    				prev = i;
    			}
    			else
    			{
    				min_dist = min_dist > abs(i-prev)?abs(i-prev):min_dist;
    				prev = i;

    			}
    		}
    	}
    }
    return min_dist;
}




#include<stdio.h>
init()
{
	return 5;}
int fun()
{
  static int count = 5;
  count = 0;
  count++;
  return count;
}

int test_main()
{
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}
