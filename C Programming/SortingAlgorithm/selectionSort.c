/*
 * selectionSort.c
 *
 *  Created on: Aug 11, 2018
 *      Author: prabhaka
 */

void selectionSort(int inp[],int n)
{
    int i = 0;
    int j = 0;
    int min = 0;
    for(i = 0; i < n; i++)
    {
    	min = i;
    	for(j = i; j<n; j++)
    	{
    		if(inp[min] > inp[j])
    		{
    			min = j;
    		}
    	}
    	//exchange j & i;
    	int temp = inp[i];
    	inp[i] = inp[min];
    	inp[min] = temp;
    }
}
