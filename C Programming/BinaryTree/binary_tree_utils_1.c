/*
 * binary_tree_utils_1.c
 *
 *  Created on: Jan 23, 2017
 *      Author: sankarsa
 */


#include "binarytree.h"
#include "Queue.h"
#include<stdio.h>
#include<limits.h>


void test_binary_utils()
{
 Node * root = CreateTree();
 int min = INT_MAX;
 int max = INT_MIN;
// FindMinMax(root, &min,&max);
 //printf("(min,max) = (%d, %d)\n", min, max);
 int x = findElement_recursive(root, 999);
 printf("Value of x = %d \n", x);

 int y = findElement_iterative(root, 99);
 printf("Value of y = %d \n", y);

 printf("Number of node = %d \n",count_nodes(root));
 printf("Number of node(iterative method ) = %d \n",count_nodes_iterative(root));
 printf("Number of node(iterative method ) = %d \n",isCompleteBinaryTreeR(root));

 printf("Number of node(iterative method ) = %d \n",isCompleteBinaryTree_iterative(root));
 printf("Is same level = %d \n",isLeafInSameLevel(root));
 printf("Is same level = %d \n",isleaf_in_samelevel_iterative(root));

}


Node * CreateTree()
{
	Node *root = CreateNode(10);

	Node *temp  = CreateNode(15);
	root->l = temp;

	 temp  = CreateNode(9);
	root->r = temp;

	temp  = CreateNode(6);
	root->r->l = temp;

	temp  = CreateNode(99);
	root->r->r = temp;

	temp  = CreateNode(-1);
	root->r->r->l = temp;
	//root->l->r = temp;

	return root;

}

void FindMinMax(Node *root, int *min, int *max)
{
	if(root == NULL)
		return;

	if(*min > root->value)
		*min = root->value;
	if(*max < root->value)
		*max = root->value;

	FindMinMax(root->l, min, max);
	FindMinMax(root->r, min, max);

}



int findElement_recursive(Node *root, int x)
{
	if(root == NULL)
	{
		return 0;
	}
	else if(root->value == x)
		return 1;
	else
	{
		return findElement_recursive(root->l, x) || findElement_recursive(root->r, x);
	}
}

int findElement_iterative(Node *root, int x)
{
	if(root == NULL)
	{
		return 0;
	}
	QUEUE *q = CreateNewQueue();

	Enqueue(q,root);
	while(q->size != 0)
	{
		int size = q->size;
		while(size > 0)
		{
			Node * data = Dequeue(q);
			if(data->value == x)
				return 1;
			data->l?Enqueue(q,data->l):0;
			data->r?Enqueue(q,data->r):0;
			size--;

		}

	}
	return 0 ;

}


int count_nodes(Node * root)
{
	if(root == NULL)
		return 0;
	else
		return 1+count_nodes(root->l)+ count_nodes(root->r);
}


int count_nodes_iterative(Node *root)
{
	int count = 0;
	if(root == NULL)
		return 0;
	else
	{
		QUEUE *q = CreateNewQueue();
		Enqueue(q, root);

		while(q->size != 0){

			int size = q->size;
			while(size > 0)
			{
				Node *n = Dequeue(q);
				count++;
				n->l?Enqueue(q, n->l):0;
				n->r?Enqueue(q, n->r):0;
				size--;
			}
		}
	}
	return count;
}


int isCompleteBinaryTreeR(Node *root)
{
	int num_nodes = count_nodes(root);
	return isCompleteBinaryTree_recursive(root,0,num_nodes);
}

int isCompleteBinaryTree_recursive(Node *root,int index, int maxcount)
{
	if(root == NULL)
		return 1;
	else
	{
		if(index >= maxcount)
			return 0;
		else
			return isCompleteBinaryTree_recursive(root->l, 2*index+1,maxcount)  &&\
					isCompleteBinaryTree_recursive(root->r, 2*index+2,maxcount);
	}

}

int isCompleteBinaryTree_iterative(Node *root)
{
	if(root == NULL)
		return 1;
	else
	{
		QUEUE *q = CreateNewQueue();
		Enqueue(q, root);
		int missing_child = 0;
		while(q->size != 0)
		{

			int size = q->size;
		//	missing_child = 0;
			while(size > 0)
			{
				Node *n = Dequeue(q);

				if(n->l != NULL)
				{
					    if(missing_child == 1)
						return 0;
					    else
						Enqueue(q,n->l);
				}
				else
					missing_child =1;


				if(n->r != NULL)
				{
					if(missing_child == 1)
						return 0;
					else
					   Enqueue(q,n->r);
				}
				else
					missing_child =1;

				size--;
			}
		}
	}
	return 1;
}


int isleaf_in_samelevel_iterative(Node *root)
{
	if(root == NULL)
		return 1;
	else
	{
		int leaflevel = 0;
		int level = 0;
		QUEUE *q = CreateNewQueue();
		Enqueue(q, root);
		while(q->size != 0)
		{

			int size = q->size;
		//	missing_child = 0;
			while(size > 0)
			{
				Node *n = Dequeue(q);


				if(n->l == NULL && n->r == NULL)
				{
					if(leaflevel == 0)
					leaflevel = level;
					else if(leaflevel != level)
						return 0;

				}
				if(n->l != NULL)
				{
						Enqueue(q,n->l);
				}
				if(n->r != NULL)
				{
					   Enqueue(q,n->r);
				}
				size--;
			}
			level++;
		}
		printf("level = %d \n", level);
	}
	return 1;
}



int isLeafInSameLevel(Node  *root)
{
int level = 0; int leafnode = 0;
	return check_leaf_same_level(root, level, &leafnode);
}



int check_leaf_same_level(Node * root, int level, int *leaflevel)
{
	if(root == NULL)
	{
		return 1;
	}
	else if(root->l == NULL && root->r == NULL)
	{
		if(*leaflevel == 0)
		{
			*leaflevel = level;
		}
		return (level == *leaflevel);
	}

	return check_leaf_same_level(root->l,level+1,leaflevel) && check_leaf_same_level(root->r,level+1,leaflevel);
}




int convert_btree_to_sum_of_left(Node *root)
{
	if(root == NULL)
		return 0;
	if(root->l == NULL && root->r == NULL)
	{
		return root->value;
	}

	root->value += convert_btree_to_sum_of_left(root->l);

	return root->value + convert_btree_to_sum_of_left(root->r); // it has to return both left + right
}
