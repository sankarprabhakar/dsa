/*
 * heap.c
 *
 *  Created on: Jan 5, 2017
 *      Author: sankarsa
 */


/*
 * Properies of Min-heap
 * 1. Heap will have minimum element in the root.
 * 2. The leaf value always greater than parent.
 * 3. it should be a complete binary tree - all internal nodes should have 2 childs ,
 *    last level node should be filled from left to right.
 *
 * */
#include<limits.h>

typedef struct heapstruct{
	int *hp;
	int heap_type; //min = 0 max =1;
	int size;
	int max_size;
}HEAP_STRUCT;

HEAP_STRUCT * CreateHeap(int capacity, int type)
{
	HEAP_STRUCT *hs = (HEAP_STRUCT *) malloc(sizeof(HEAP_STRUCT));
	hs->hp = (int *) malloc(capacity);
	hs->max_size = capacity;
	hs->heap_type = type;
	hs->size = 0;
	return hs;
}

void destructHeap(HEAP_STRUCT *hs)
{
	free(hs->hp);
	free(hs);
}

int insertElement(int data, HEAP_STRUCT *hs)
{
	int i = 0;
	if(!hs)
	{
		return -1;
	}
	else
	{
	   if(hs->size < hs->max_size)
	   {
		   hs->size++;
		   hs->hp[hs->size -1] = data; //data is inserted.
		   i = hs->size-1;

		   //heapify from inserted node till the root.. or till everything is heapified..
		   while(i != 0 && isSwapRequried(i, hs))
		   {
			   swap_elements(&hs->hp[getParent(i)], &hs->hp[i]);
			   i = getParent(i);
		   }
	   }
	   else
	   {
		   return -1;
	   }
	}
}

int changeKey(int i , int key, HEAP_STRUCT *hs)
{
	if(i < hs->size)
	{

		hs->hp[i] = key;

		//heapify from inserted node till the root.. or till everything is heapified..
	   while(i != 0 && isSwapRequried(i, hs))
	   {
		   swap_elements(&hs->hp[getParent(i)], &hs->hp[i]);
		   i = getParent(i);
	   }
	}
	else
		return -1;


}

int extractRoot(HEAP_STRUCT *hs)
{
	if(hs->size == 0)
	{
		return -1;
	}
	else if(hs->size == 1)
	{
		hs->size--;
		return hs->hp[0];
	}

	int root = hs->hp[0];
	hs->hp[0] = hs->hp[hs->size-1];
	hs->size--;
	Heapify(hs , 0);

	return root;

}

int deleteKey(int key, HEAP_STRUCT *hs)
{
	int i = 0;
	for(; i> hs->size ; i++)
	{
		if(hs->hp[i] == key)
		{
			break;
		}
	}
	if(i >= hs->size)
	{
		return -1;
	}
	int insert_val = hs->heap_type ?INT_MAX:INT_MIN;
	changeKey(i,insert_val,hs);
	print_heap(hs);
	extractRoot(hs);

}

int Heapify(HEAP_STRUCT *hs, int idx)
{
	int left = getLeftIndex(idx);
	int right = getRightIndex(idx);
	int smallest = idx;
	if(left < hs->size && CompareNodes(idx,left,hs))
		smallest = left;
	if(right < hs->size &&  CompareNodes(smallest,right,hs))
		smallest = right;
	if(smallest != idx)
	{
		swap_elements(&hs->hp[smallest],&hs->hp[idx]);
		Heapify(hs, smallest);
	}

}
/*utility functions*/

int getLeftIndex(int idx)
{
	return 2*idx +1;
}
int getParent(int idx)
{
	return (idx-1)/2;
}

int getRightIndex(int idx)
{
	return 2*idx +2;
}

int get_root(HEAP_STRUCT *hs)
{
	hs->hp[0];
}

int print_heap(HEAP_STRUCT *hs)
{
	int i = 0;
	for(;i < hs->size; i++)
	{
		printf("%d \t", hs->hp[i]);
		if(i==0)
			printf("\n");
		else if(i == 1)
				{

				}
		else if(!(i & (i-1)))
		{
			printf("\n");
		}

	}
	return 0;
}

int isSwapRequried(int i, HEAP_STRUCT *hs)
{
	if(hs->heap_type)
		return (hs->hp[getParent(i)] < hs->hp[i]);
	else
		return (hs->hp[getParent(i)] > hs->hp[i]);
}

int CompareNodes(int idx1, int idx2,HEAP_STRUCT *hs)
{
	/*for max heap;
	 * 1 -> if idx1 is less than idx2
	 * for min heap
	 * 1 -> if idx1 is greater than idx2
	 * */
	if(hs->heap_type)
		return (hs->hp[idx1] < hs->hp[idx2]);
	else
		return (hs->hp[idx1] > hs->hp[idx2]);
}


int swap_elements(int *x, int*y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}


/*test functions*/
int test_fun1()
{
	HEAP_STRUCT *s = CreateHeap(10,1);
	insertElement(10,s);
	insertElement(100,s);
	insertElement(50,s);
	insertElement(500,s);
	insertElement(1000,s);
	//changeKey(2, 10000, s);
	//extractRoot(s);
	deleteKey(100, s);
	printf("\n***********\n");
	print_heap(s);

}
