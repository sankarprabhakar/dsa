/*
 * insertionSort.c
 *
 *  Created on: Aug 11, 2018
 *      Author: prabhaka
 */

void insertionSort(int inp[], int n)
{
	int i = 0;
	int j = 0;
	int newNo = 0;
	for(i = 1; i<n;i++)
	{
		newNo = inp[i];
		j = i-1;
		while(j >= 0 && inp[j] > newNo)
		{
			inp[j+1] = inp[j];
			j--;
		}
		inp[j+1] = newNo;
	}
}
