/*
 * countingSort.c
 *
 *  Created on: Aug 12, 2018
 *      Author: prabhaka
 */
#define RANGE 15
void countingSort(int inp[], int n)
{
	int count[RANGE] = {0};
	int i = 0;
	//printf("Hello");
	for(i = 0; i<n;i++)
	{
		count[inp[i]]++;
	}
	printArray(count, RANGE);
	/*Finding the position of the variable*/
#if 1
	for(i = 1; i< RANGE;i++)
	{
		count[i] += count[i-1];
	}
	int output[n];
	for(i = 0; i< n;i++)
	{
		output[count[inp[i]]-1] = inp[i];
		count[inp[i]]--;
	}
	for(i = 0; i< n;i++)
	{
		inp[i] = output[i];
	}
#endif
}
