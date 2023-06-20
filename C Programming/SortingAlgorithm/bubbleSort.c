/*
 * bubbleSort.c
 *
 *  Created on: Aug 11, 2018
 *      Author: prabhaka
 */

void bubbleSort(int a[], int n)
{
	int i = 0;
	int j = 0;
	for(i =0 ; i < n ; i++)
		for(j = 0 ; j < n-1-i ; j++)//last i elements are sorted
			if(a[j+1] < a[j])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
 			}
}


