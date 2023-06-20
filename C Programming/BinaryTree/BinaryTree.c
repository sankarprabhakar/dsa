/*
 * BinaryTree.c
 *
 *  Created on: Apr 26, 2016
 *      Author: sankarsa
 */
#include<stdio.h>

#include<stdlib.h>
#include "Queue.h"
#include "Stack.h"
#include "binarytree.h"

void main()
{
	BT_main();
//	test_binary_utils();

}

void BT_main()
{
	root = insert(root,10);
	insert(root,5);
	insert(root,7);
	insert(root,4);
	insert(root,20);
	insert(root,17);
	insert(root,18);
	insert(root,14);
	insert(root,16);
/*
	printf("in order \n");
	inorder(root);

	printf("Pre order \n");
	preorder(root);

	printf("Post order \n");
	postorder(root);

	printf("\n height = %d \n", height(root));

BFS(root);

	DFS(root);
	printf("\nin order");
		inorder(root);

	DeleteNode(root,10);

	printf("\nin order");
		inorder(root);
	Node *p,*s;
	Inorder_Pred_successor(root,&p,&s, 10);
	if(p)
	printf("P - %d \n", p->value);
	else
		printf("No predicissor\n");

	if(s)
		printf("S - %d \n", s->value);
	else
			printf("No successor\n");




	Node *snode = Search_without_Recursion(root, 7);
	if(snode)
	printf("SNode = %d \n",snode->value );
	else
		printf("The node is not found \n");
*/
	printf("Deletion \n");
	//DeleteBTree(root);
	/*printf("B Tree is deleted \n");
	int h = 0;
	printf("Diameter = %d\n" ,DiameterMod(root, &h));
	printf("Diameter = %d\n" ,h);*/

	//printf("Height = %d\n",height_using_levelorder(root));

	//MorrisTraversal_inorder(root);
	//MinimumValue(root);

	//inorder_iteration(root);
	create_threaded_binary_tree(root);
	traverse_inorder(root);
}

//DFS = Stack
//BFS ==> Uses Queue..
/*
 * 1. Add root to Q
 * 2. dequeue and visit the node
 * 3. Enqueue all the childs..
 * 4. Continue from step 2; till queue is empty
 * */

void BFS(Node *node)
{

	QUEUE *q = CreateNewQueue();

	Node *tmp;
	printf("BFS --");
	Enqueue(q, (void *)node);
	while((tmp = Dequeue(q)) != NULL)
	{
		tmp = (Node *)tmp;
		printf(" %d ", tmp->value);
		Enqueue(q, (void *)tmp->l);
		Enqueue(q, (void *)tmp->r);
	}

}
/*
 * 1. Mark root as visited and put it to stack
 * 2. Select the unvisited left or unvisited right sub tree. Visit it and put it in stack..
 * 3. if no more child. Pop the stack and do step 2. till the no more element to pop.
 *
 *
 * */
void DFS(Node *node)
{

	Node *temp = node;
	Node *Next = NULL;
	STACK *s = CreateStack();
	temp->visited =1;
	Push(s,(void *)temp);
	printf("DFS:: %d ", node->value);

	while(temp != NULL)
	{
		if(temp->l && !temp->l->visited)
		{
			temp = temp->l;
			temp->visited = 1;
			printf("%d ", temp->value);
			Push(s,(void *)temp);
		}
		else if(temp->r && !temp->r->visited)
		{
			temp = temp->r;
			temp->visited = 1;
			printf("%d ", temp->value);
			Push(s,(void *)temp);
		}
		else
		{
			/*it is better to peep first and check and pop*/
			temp = Pop(s);
		}
	}
}


Node * CreateNode(int v)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->l = p->r = NULL;
	p->value = v;
	p->r_thread = 0;
	p->visited = 0;
	return p;
}

Node* insert_rec(Node *n,int v)
{
	if(n == NULL)
	{
		return  CreateNode(v);
	}
	else if(v <= n->value )
	{
		n->l = insert(n->l,v);
	}
	else
	{
		n->r = insert(n->r,v);
	}

	return n;
}


Node* insert(Node *n,int v)
{
	Node *p = n;
	if(n == NULL)
	{
		return  CreateNode(v);
	}
	while(n)
	{
		p = n;
		if(v <= n->value )
		{
			n = n->l;// = insert(n->l,v);
		}
		else
		{
			n = n->r; // = insert(n->r,v);
		}
	}
	p->value > v?(p->l=CreateNode(v)):(p->r=CreateNode(v));


	return n;
}


int height(Node *n)
{
	 if(n == NULL)
	 {
		return 0;
	 }
	 int left = height(n->l);
	 int right = height(n->r);
	 printf("Left = %d Right = %d \n",left,right);

	int h = MAX(left,right);
	h =  1 + h;
	printf("H = %d\n", h);
	return h;

}

void inorder(Node *n)
{
	 if(n == NULL)
	 {
		 return;

	 }
	 inorder(n->l);
	 printf("%d ",n->value);
	 inorder(n->r);
}

/*
 *  1. cur = root;
 *  2. if(cur != NULL)
 *  		push to stack
 *  		cur =  cur->left
 * 	3.  else pop out from stack. print the data, cur = cur->r;
 * 	4.  Go to step 2..
 *
 * */

void inorder_iteration(Node *n)
{

	 if(n == NULL)
		 return;

	 STACK *it_stk = CreateStack();
	 if(it_stk == NULL)
		 return;

	 while(n != NULL || Peep(it_stk) != NULL)
	 {
		 if(n!=NULL)
		 {
		  Push(it_stk,n);
		  n = n->l;
		 }
		 else
		 {
		  n = Pop(it_stk);
		  printf("%d ",n->value);
		  n = n->r;
		 }
	 }
}



void preorder(Node *n)
{
	 if(n == NULL)
	 {
		 return;

	 }

	 printf("%d ",n->value);
	 preorder(n->l);
	 preorder(n->r);
}


void postorder(Node *n)
{
	 if(n == NULL)
	 {
		 return;

	 }
	 postorder(n->l);
	 postorder(n->r);
	 printf("%d ",n->value);
}

/*
 * 1. Leaf node -  Delet it - Need its parent node to delete it
 * 2. Node with one subtree - connect "parent" to "child node" of "to be deleted" node -
 * 		only parent is needed
 * 3. Node with two subtree - copy the data from in-order successor; and delete the
 * 		inorder successor node. Now the problem would be reduce to either case#1 or case2.
 * 		"We need parent node of in-order successor to delete it".
 *
 * */
void DeleteNode(Node *n, int d)
{

	//Find the node..
	Node *nf = NULL, *p = NULL;
	nf = SearchNode(n,d,&p);
	if(nf == NULL)
	{
		printf("Data not found \n");

	}
	else{
		printf("Data found = %d",nf->value);
		if(p)
		{
			printf("Parent data = %d ", p->value);
		}
		printf("\n");
	}


	if(nf != NULL && nf->l != NULL && nf->r != NULL)
	{
		Node *pre = FindInorderSucessor(nf, &p);
		nf->value = pre->value;
		DoDeletion(pre,p);

	}
	else
	{

		DoDeletion(nf, p);
	}
	//find inorder successor
		//FindInorderSucessor(n, &p);

}

Node *FindInorderSucessor(Node *n, Node **p)
{
	Node *tmp = n->r;
	*p = n;
	Node *pre = n;
	while(tmp)
	{
		*p = pre;
		pre = tmp;
		tmp = tmp->l;
	}
	return pre;
}


DoDeletion(Node *nf, Node *p)
{
	if(nf != NULL && nf->l == NULL && nf->r == NULL)
	{
		//leaf node..
		if(p)
		{
			if(p->l == nf)
			{
				free(nf);
				p->l = NULL;
			}
			else
			{
				free(nf);
				p->r = NULL;
			}
		}
		else
		{
			free(nf);
			root = NULL;
		}
	}//Check if it has only one sub tree
	else if(nf  && (nf->l == NULL))
	{
		if(p->l == nf)
		{
				p->l = nf->r;
		}
		else
		{
			p->r = nf->r;
		}

	}//Check if it has only one sub tree
	else if(nf  && (nf->r == NULL))
	{
			if(p->l == nf)
			{
					p->l = nf->l;
			}
			else
			{
				p->r = nf->l;
			}

	}//both the sub trees are valid
}


Node * SearchNode(Node *n,int val, Node **p)
{
	//static Node *parent;
	if(n == NULL)
	{
		return NULL;
	}
	else if(n->value > val)
	{
		*p = n;
		return SearchNode(n->l,val,p);

	}else if (n->value < val)
	{
		*p = n;
		return SearchNode(n->r,val,p);
	}
	else
	{
		return n;
	}
}

void Inorder_Pred_successor(Node *root, Node **p, Node **s, int key)
{
	Node *temp = NULL;
	if(root == NULL)
	{
		return;
	}
	if(root->value == key)
	{
		if(NULL != root->r)
		{
			 temp = root->r;
			 while(temp->l)
				temp = temp->l;
			 *s = temp;
		}
		if(NULL != root->l)
		{
			temp = root->l;
			while(temp->r)
				temp = temp->r;
			*p = temp;
		}
		return ;
	}
	else if(root->value > key)
	{
		*s = root;
		Inorder_Pred_successor(root->l, p,s,key);
	}
	else if(root->value < key)
	{
		*p = root;
		Inorder_Pred_successor(root->r, p,s,key);
	}
}



Node * Search_without_Recursion(Node *root, int key)
{
		Node *temp = root;
		if(temp == NULL)
		{
			return NULL;
		}
		else
		{
			while(temp && temp->value != key)
			{
				if(temp->value > key)
				{
					temp = temp->l;
				}
				else if(temp->value < key)
				{
					temp = temp->r;
				}
			}
		}
		return temp;
}



void DeleteBTree(Node *root)
{

		if(root == NULL)
		{
			printf("R hitting base condition");
			return ;
		}
		//if(root->l != NULL)
		{
			DeleteBTree(root->l);
		}
		//if(root->r != NULL)
		{
			DeleteBTree(root->r);
		}
		printf("Going to delete %d\n", root->value);
		free(root);

		return;

}

int Diameter(Node *root)
{
	if(root != NULL)
	{
		int lh = height(root->l);
		int rh = height(root->r);
		int ld = Diameter(root->l);
		int rd = Diameter(root->r);
		return MAX(lh+rh+1,MAX(ld,rd));
	}
	return 0;

}


int DiameterMod(Node *root, int *height)
{
	int lh = 0, rh = 0, ld=0,rd=0;
	if(root != NULL)
	{

		 ld = DiameterMod(root->l, &lh);
		 rd = DiameterMod(root->r, &rh);

		 printf("Root->value = %d \n",root->value);


		*height = 1 + (MAX(lh,rh));
		printf("lh = %d  rh =%d\n",lh, rh);

		return MAX(lh+rh+1,MAX(ld,rd));


	}
	else
	{
		*height = 0;
		return 0;
	}
}


int height_using_levelorder(Node *root)
{
	Node *temp = root;
	int height = 0;
	int node_count = 0;
	//int nodeCount = 0;
	Node *qout = NULL;
	QUEUE *q = CreateNewQueue();
	Enqueue(q,(void *)root);
	while(1)
	{
		node_count = q->size;
		if(node_count == 0)
		{
			return height;
		}
		else
		{
			height++;
		}

		while(node_count > 0)
		{
			qout = (Node*)Dequeue(q);
			if(qout->l)
			Enqueue(q,qout->l);
			if(qout->r)
			Enqueue(q,qout->r);

			node_count--;
		}
	}
}

/*
 * 1. Initialize current as root..
 * 2. While current is not NULL.
 * 		a. Check if current->left is null
 * 				i. print current -> value.
 * 				ii. current = current->right.
 * 		b.if current->left is not null
 * 				i. make current as the right most element of currents left child.
 * 					#if the right most element threaded back to curren--its a looping...check and correct it
 * 				ii. Go to left child; current = current->left.
 *
 * */
void MorrisTraversal_inorder(Node *root)
{
	Node *current = root;
	while(current != NULL)
	{
		if(current->l == NULL)
		{
			printf("%d ",current->value);
			current = current->r;
		}
		else
		{
			Node *pre = current->l;
			while(pre->r != NULL && pre->r != current )
				pre = pre->r;
			if(pre->r == NULL)
			{
				pre->r = current;
				current = current->l;
			}
			else
			{
				pre->r = NULL;
				printf("%d ",current->value);
				current = current->r;
			}

		}
	}

}

int MinimumValue(Node *root)
{
	Node *temp = root;
	while(temp->l != NULL)
	{
		temp = temp->l;
	}
	printf("Minum value = %d \n", temp->value);
}


void create_threaded_binary_tree(Node *root)
{
	Node *cur = root, *pre = NULL;
	if(cur == NULL)
		return;

	while(cur != NULL)
	{

		if(cur->l != NULL)
		{
			/*Find predecessor of current and join its right to current node*/
			pre = cur->l;
			while(pre->r != NULL && cur != pre->r)
				pre = pre->r;
			if(pre->r == NULL)
			{
				pre->r = cur;
				pre->r_thread = 1;
				/*Now move on to next left node*/
				 cur = cur->l;
			}
			else
			{
				/*cycle detected, so traverse the right node..*/
				cur = cur->r;
			}

		}
		else
		{
			cur = cur->r;
		}
	}

}

Node *getLeftMostNode(Node *r)
{
	if(r == NULL)
		return NULL;
	else
	{
		while(r->l)
			r = r->l;
		return r;
	}
}
void traverse_inorder(Node *root)
{

	Node *cur = getLeftMostNode(root);
	while(cur != NULL)
	{
		printf("%d ", cur->value);
		if(cur->r_thread)
		{
			cur = cur->r;
		}
		else
		{
		   cur = getLeftMostNode(cur->r);
		}

	}
}
