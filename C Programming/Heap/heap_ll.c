/*
 * heap_ll.c
 *
 *  Created on: Jan 5, 2017
 *      Author: sankarsa
 */

#include <stdio.h>
#include "Queue.h"
typedef struct hnode{

	int  data;
    struct hnode *p;
    struct hnode *l;
    struct hnode *r;
}HNODE;

HNODE *createAndInsert(HNODE *inspoint,int val);
HNODE *GetInsertionPoint(root);
HNODE *root = NULL;
int extractMinimum(HNODE *root);
void getLastNode(HNODE *root, HNODE **lastNode);
int test_fun2()
{
	 printf("in test funciton  \n");

 insert(10,&root);
 insert(15,&root);
 insert(40,&root);
 insert(35,&root);
 insert(30,&root);
 insert(5,&root);
 insert(20,&root);

 print_levelorder(root);
 extractMinimum(root);
// print_preorder(root);
 print_levelorder(root);
 extractMinimum(root);
// print_preorder(root);
 print_levelorder(root);


}

/*finding the insertion point
 * 2 - ways possible
 * 	1. level order
 * 	2. recursion
 *
 * */

int insert(int val, HNODE **root)
{
	//insert at a point and heapify till the root.

	HNODE *inspoint = NULL;
	if(NULL == *root )
	{
		*root = createAndInsert(inspoint,val);
		return 0;
	}
	inspoint = GetInsertionPoint(*root);
	HNODE *insNode = createAndInsert(inspoint,val);
	/*till the */
	while(NULL != insNode->p)
	{
            if(insNode->data < insNode->p->data)
            {
            	int t = insNode->data;
            	insNode->data = insNode->p->data;
            	insNode->p->data = t;

            	insNode = insNode->p;
            }
            else
            	break;
	}

	return 1;
}

int heapify(HNODE *root)
{
	HNODE *temp = root;
	HNODE *smallVal = root;
    while(temp != NULL)
    {
    	smallVal = NULL;
    	//find the smallest amoung the left,right and root;
    	if(temp->l)
    	{
    		smallVal = temp->data > temp->l->data?temp->l:temp;
    	}
    	if(temp->r)
    	{
    		smallVal = smallVal->data > temp->r->data ? temp->r:smallVal;
    	}
    	if(smallVal && (temp != smallVal))
    	{
    		int val = temp->data;
    		temp->data = smallVal->data;
    		smallVal->data = val;
    		temp = smallVal;
    	}
    	else
    		break;

    }
}

int extractMinimum(HNODE *root)
{
	//take out data from root
	//find the last element..
    //replace the data from last element to root
	//heapify from root.

	int minVal = root->data;
	HNODE *temp = root;
	HNODE *lastNode = NULL;
    getLastNode(root, &lastNode);

    root->data = lastNode->data;
    int x = (lastNode == lastNode->p->l)?(lastNode->p->l =NULL):(lastNode->p->r =NULL);
    free(lastNode);
	heapify(root);

	return minVal;
}


void getLastNode(HNODE *root, HNODE **lastNode) //, int level, int *maxlevel, HNODE **lastNode)
{

	if(!root) return;
	if((root  && !root->l && !root->r))
	{
		*lastNode = root;
		return;
	}
	getLastNode(root->l,lastNode);
	getLastNode(root->r,lastNode);

}
HNODE *createAndInsert(HNODE *inspoint,int val)
{
     printf("CreateAndInsert\n");
	HNODE *newNode = (HNODE *)malloc(sizeof(HNODE));
	memset(newNode, 0, sizeof(HNODE));
	newNode->l = newNode->r = newNode->p = NULL;
	newNode->data = val;
	if(inspoint != NULL)
	{
	if(inspoint->l)
		inspoint->r = newNode;
	else
		inspoint->l = newNode;

	newNode->p = inspoint;
	}
	return newNode;
}

HNODE *GetInsertionPoint(HNODE *root)
{
	HNODE *ins = NULL;
	int insertlv = 0;
	find_insertion_node(root, 0, &insertlv, &ins);
	return ins;
}

void find_insertion_node(HNODE *root, int level, int *insertlevel, HNODE **point)
{
		if((root->l && !root->r) || (!root->l && !root->r) )
		{
			if(*insertlevel == 0)
			{
				*insertlevel = level;
				*point = root;
			}
			else if(*insertlevel > level)
			{
				*insertlevel = level;
				*point = root;
			}
			return;
		}
		find_insertion_node(root->l, level+1,insertlevel,point);
		find_insertion_node(root->r, level+1,insertlevel,point);
		return;
}

int print_inorder(HNODE *root)
{
	if(!root) return 0;
	print_inorder(root->l);
	printf("-%d-", root->data);
	print_inorder(root->r);
return 0;
}

int print_preorder(HNODE *root)
{
	if(!root) return 0;

	printf("%d \t", root->data);
	print_preorder(root->l);
	print_preorder(root->r);
return 0;
}

int print_levelorder(HNODE *root)
{
   QUEUE *q = CreateNewQueue();
   Enqueue(q,root);

   while(q->size)
   {
	   int size = q->size;
	   while(size > 0)
	   {
		   size--;
		   HNODE *node = (HNODE*)Dequeue(q);
		   printf("%d(%d) ", node->data,node->p?node->p->data:0);
		   if(node->l)Enqueue(q,node->l);
		   if(node->r)Enqueue(q,node->r);
	   }
	   printf("\n");
   }
}
// Root - Left - Right
