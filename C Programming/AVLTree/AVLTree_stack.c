/*
 * AVLTree_stack.c
 *
 *  Created on: Aug 19, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include"ds.h"
#include"Stack.h"

NODE *insert_using_stack(NODE *node,int key)
{
	if(node == NULL)
	{
		return CreateNode( key);
	}
	NODE *currNode = node;

	STACK *mystack = CreateStack();

	while(currNode != NULL)
	{
		if(currNode->key > key)
		{
			Push(mystack, (void *)currNode);
			currNode = currNode->l;
			/*
			if(currNode->l)
			{
				currNode = currNode->l;
			}
			else
			{
				currNode->l = CreateNode( key);
				break;
			}*/
		}
		else
		{

			Push(mystack, (void *)currNode);
			currNode = currNode->r;
			/*
			if(currNode->r)
			{
				currNode = currNode->r;
			}
			else
			{
				currNode->r = CreateNode( key);
				break;
			}
			*/

		}
	}
	/*inserting the new node*/
	NODE *insertion_point = (NODE *)Peep(mystack);
	if(insertion_point->key > key)
	{
		insertion_point->l = CreateNode(key);
	}
	else
	{
		insertion_point->r = CreateNode(key);
	}

	/*Correct the height*/
	NODE *poped = NULL;
	int balance = 0;
	NODE *RotateCentre = NULL;
	NODE *peeped = NULL;
	while((poped = (NODE *)Pop(mystack)) != NULL)
	{
		RotateCentre = NULL;
		//adjust the height of elements in the stack;
		int lh = height(poped->l);
		int rh = height(poped->r);
		int h = MAX(lh,rh );
		poped->h = h + 1;

		balance = GetBalanceFactor(poped);
		printf("balance = %d \n",balance);
		if(balance > 1 && poped->l && key < poped->l->key) //if balance factor > 1 implies existence of left child..
		{
			RotateCentre = RotateRight(poped);
			peeped = (NODE *)Peep(mystack);
			if(peeped && peeped->l == poped)
			{
				peeped->l = RotateCentre;
			}
			else if(peeped && peeped->r == poped)
			{
				peeped->r = RotateCentre;
			}
			else
			{
			  node = RotateCentre;
			}
			continue;
		}
		if(balance < -1  && poped->r && key > poped->r->key)
		{
			RotateCentre = RotateLeft(poped);
			peeped = (NODE *)Peep(mystack);
			if(peeped && peeped->l == poped)
			{
				peeped->l = RotateCentre;
			}
			else if(peeped && peeped->r == poped)
			{
				peeped->r = RotateCentre;
			}
			else
			{
			  node = RotateCentre;
			}
			continue;
		}

		if(balance > 1  && poped->l && key > poped->l->key)
		{
			poped->l = RotateLeft(poped->l);
			RotateCentre = RotateRight(poped);
			peeped = (NODE *)Peep(mystack);
			if(peeped && peeped->l == poped)
			{
				peeped->l = RotateCentre;
			}
			else if(peeped && peeped->r == poped)
			{
				peeped->r = RotateCentre;
			}
			else
			{
			  node = RotateCentre;
			}

			continue;
		}
		if(balance < -1  && poped->r && key< poped->r->key)
		{
			poped->r = RotateRight(poped->r);
			RotateCentre = RotateLeft(poped);
			peeped = (NODE *)Peep(mystack);
			if(peeped && peeped->l == poped)
			{
				peeped->l = RotateCentre;
			}
			else if(peeped && peeped->r == poped)
			{
				peeped->r = RotateCentre;
			}
			else
			{
			  node = RotateCentre;
			}
			continue;
		}
	}

	return node;

}

NODE *DeleteNode(NODE *node, int key)
{
	/*Traverse till the node to be delete & push the path to stack*/
	STACK *mystack = CreateStack();
	NODE *currNode = node;
	while(currNode && currNode->key != key)
	{
		Push(mystack, currNode);
		if(currNode->key > key)
		{
			currNode = currNode->l;
		}
		else
		{
			currNode = currNode->r;
		}
	}

	/**/
	if(!currNode)
	{
		printf("Data not found\n");
		return NULL;
		//Clear off the stack and return
	}
	NODE *poped;
	NODE *peeped;
	if(currNode->l != NULL && currNode->r !=NULL)
	{
	   printf("Deleting a node with two subchild\n");
		NODE *tobeDeleted = currNode;
		Push(mystack, currNode);
		//find the inorder sucessor
		currNode = currNode->r;

		while(currNode->l != NULL)
		{
			Push(mystack, currNode);
			currNode = currNode->l;
		}
		//Push(mystack, currNode);
		tobeDeleted->key = currNode->key;
	}

	//Push(mystack, currNode);

	if(currNode->l == NULL || currNode->r == NULL)
	{
		NODE *temp = currNode->l?currNode->l:currNode->r;
		if(temp == NULL)
		{
			printf("Deleting the leafNode\n");
			peeped = Peep(mystack);
			if(peeped)
			{
				(peeped->l == currNode)?(peeped->l = NULL):(peeped->r = NULL);
				//free(currNode);
			}
			else
			{
				printf("Deleteing only node of tree\n");
				free(currNode);
				return NULL;
			}
		}
		else
		{
			printf("Deleting a node with only one sub child\n");
			peeped = Peep(mystack);
			if(peeped->l == currNode)
			{
				peeped->l = temp;
			}
			else
			{
				peeped->r = temp;
			}
		}
	}


	while((poped = Pop(mystack)) != NULL)
	{
		//recompute the
		poped->h = MAX(height(poped->l), height(poped->r));
		poped->h += 1;

		int balance = GetBalanceFactor(poped);

		if(balance > 1 && GetBalanceFactor(poped->l) >= 0)
		{

			 NODE *RotateCentre = RotateRight(poped);
			 NODE *peeped = Peep(mystack);
			 if(peeped && peeped->l ==  poped)
			 {
				 peeped->l = RotateCentre;
			 }
			 else if(peeped && peeped->r == poped)
			 {
				 peeped->r = RotateCentre;
			 }
			 else
			 {
				node = RotateCentre;
			 }
		}

		if(balance < -1 && GetBalanceFactor(poped->r) <= 0)
		{

			 NODE *RotateCentre = RotateLeft(poped);
			 NODE *peeped = Peep(mystack);
			 if(peeped && peeped->l ==  poped)
			 {
				 peeped->l = RotateCentre;
			 }
			 else if(peeped && peeped->r == poped)
			 {
				 peeped->r = RotateCentre;
			 }
			 else
			 {
				node = RotateCentre;
			 }
		}
		if(balance > 1 && GetBalanceFactor(poped->l) < 0)
		{

			poped->l = RotateLeft(poped->l);

			 NODE *RotateCentre = RotateRight(poped);
			 NODE *peeped = Peep(mystack);
			 if(peeped && peeped->l ==  poped)
			 {
				 peeped->l = RotateCentre;
			 }
			 else if(peeped && peeped->r == poped)
			 {
				 peeped->r = RotateCentre;

			 }
			 else
			 {
				node = RotateCentre;

			 }
		}

		if(balance < -1 && GetBalanceFactor(poped->r) > 0)
		{

			 poped->r = RotateRight(poped->r);
			 NODE *RotateCentre = RotateLeft(poped);
			 NODE *peeped = Peep(mystack);
			 if(peeped && peeped->l ==  poped)
			 {
				 peeped->l = RotateCentre;
			 }
			 else if(peeped && peeped->r == poped)
			 {
				 peeped->r = RotateCentre;

			 }
			 else
			 {
				node = RotateCentre;

			 }
		}

	}
	//Push data to be deleted to stack.
	//Push(mystack, currNode);
return node;
}

