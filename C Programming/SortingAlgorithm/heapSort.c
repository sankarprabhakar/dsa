/*
 * heapSort.c
 *
 *  Created on: Aug 12, 2018
 *      Author: prabhaka
 */
/*
 * 1. build a max heap
 * 2. move large element to end of heap , reduce size of heap.
 * 3. heapify on root again and repeat step 2 till size becomes 1
 *
 * */
int getParent(int i)
{
	return (i-1)/2;
}
int getLeft(int i)
{
	return (i *2) + 1;
}
int getRight(int i)
{
	return (i *2) + 2;
}
void swap(int *a, int *b)
{
	 int t = *a;
	 *a = *b;
	 *b = t;
}
void heapify(int inp[], int n, int root)
{

    if(root >= n)
    	return;
    int largest = root;
    int left = getLeft(root);
    int right = getRight(root);
    if(left < n && inp[largest] < inp[left])
    {
    	largest = left;
    }
    if(right < n && inp[largest] < inp[right])
    {
       largest = right;
    }
    if(largest != root)
    {
    	swap(&inp[root], &inp[largest]);
    	heapify(inp,n,largest);
    }

}

void heapSort(int inp[], int n)
{
	//heapify the array
	// to heapify any array start from the last parent and heapify up recursively
    int i = n/2-1;
    for(;i>=0; i--)
    {
    	heapify(inp,n,i);
    }
    printArray(inp,n);
    for(i = n-1; i >= 0 ; i--)
    {
    	swap(&inp[i], &inp[0]);
    	heapify(inp,i,0);

    }

}
