/*
 * mergeSort.c
 *
 *  Created on: Aug 11, 2018
 *      Author: prabhaka
 */


void mergeSort(int inp[], int l, int r)
{
	if(l < r)
	{
		int m = l+(r-l)/2;;
		mergeSort(inp,l,m);
		mergeSort(inp,m+1,r);
		//merge(inp, l,m,r);
		my_merge(inp,l,m,r);
	}
}


void merge(int inp[], int l , int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	int i = 0,j =0;
	for(i = 0; i < n1; i++)
		L[i] = inp[l+i];
	for(i = 0; i < n2; i++)
		R[i] = inp[m+1+i];

	int k = l;
	i = 0; j = 0;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			inp[k++] = L[i++];
		}
		else
		{
			inp[k++] = R[j++];
		}
	}
	while(i < n1)
	{
		inp[k++] = L[i++];
	}
	while(j < n2)
	{
		inp[k++] = R[j++];
	}
}

void my_merge(int inp[], int l, int m, int r)
{
	int r_start = m+1;
	while(l<=m && r_start <= r ){
	if(inp[l] > inp[r_start])
	{
		int tocopy = inp[r_start];
		int j = r_start;
		while(j > l)
		{
			inp[j] = inp[j-1];
			j--;
		}
		inp[j] = tocopy;
		l++;
		m++;
		r_start++;
	}
	else
	{
		l++;
	}
 }
}
