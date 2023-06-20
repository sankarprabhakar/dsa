/*
 * quickSort.c
 *
 *  Created on: Aug 11, 2018
 *      Author: prabhaka
 */

/**/
void quickSort(int inp[],int low, int high)
{
	if(low < high)
	{
		int pivot = partition(inp,low,high);
		quickSort(inp, low, pivot-1);
		quickSort(inp, pivot+1,high);
	}
}

int partition(int inp[], int low , int high)
{

	int key = inp[high];
	int i = low-1;
	int j = 0;
	for(j = low ; j <= high-1; j++)
	{
        if(inp[j] < key)
        {
        	i = i+1;
        	int temp = inp[i];
        	inp[i] = inp[j];
        	inp[j] = temp;
        }
	}
	//place to put the pivot
	i = i+1;
	int temp = inp[i];
	inp[i] = inp[high];
	inp[high] = temp;

	return i;
}
