/*
 * main.c
 *
 *  Created on: Aug 11, 2018
 *      Author: prabhaka
 */
void printArray(int inp[], int n);
void main()
{

	printf("Hello world");
	int inp[] = {10,7,9,2,1,8,6,3,4,5};
	int n = 10;
	printArray(inp, n);
	//bubbleSort(inp,n);
	//selectionSort(inp,n);
	//insertionSort(inp,n);
	//quickSort(inp,0,n);
	//mergeSort(inp,0,n-1);
	//countingSort(inp,n);
//	radixSort(inp,n);
	heapSort(inp,n);
	printArray(inp, n);
}

void printArray(int inp[], int n)
{
	int i = 0;
	printf("\nArray\n");

	for(i = 0 ; i<n ;i++)
	{
		printf("%d ",inp[i]);
	}
}
