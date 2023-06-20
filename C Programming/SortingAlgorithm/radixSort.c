/*
 * radixSort.c
 *
 *  Created on: Aug 12, 2018
 *      Author: prabhaka
 */

/*
 * 1. Sort the numbers based on ones, hundreds and thousand's places
 *

 * */
void countSortbyRandix(int inp[],int n, int place);
int getMax(int inp[], int n)
{
	int max = 0;
	int i = 0;
	for(i = 0; i<n; i++)
	{
		if(inp[i] > max)
			max = inp[i];
	}
}
void radixSort(int inp[], int n)
{

	int max = getMax(inp,n);
	int place = 1;
	for(place = 1; (max/place) != 0 ; place *= 10)
	{
		countSortbyRandix(inp,n,place);
	}

}
void countSortbyRandix(int inp[],int n, int place)
{
	int count[10] = {0};
	int i = 0;
	for(i = 0 ; i<n ; i++)
	{
        count[((inp[i])/place) % 10]++;
	}
	for(i = 1 ; i<10 ; i++)
	{
		count[i] += count[i-1];
	}
	//arrange the data to output
	int output[n];
	for(i = n-1; i >= 0 ; i--) //this works
	//for(i = 0; i < n ; i++) --> array may be sorted by prevous face value. eg 1 2 3 4 5 899. as input output will
	// 5,4 3,2,899
	{
		int faceval = ((inp[i]/place) % 10);
		output[count[faceval]-1] = inp[i];
		count[faceval]--;
	}
	//output to input
	for(i = 0 ; i<n ; i++)
	{
		inp[i] = output[i];
	}
	printArray(inp,n);
}
