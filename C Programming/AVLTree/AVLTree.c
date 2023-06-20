/*
 * main.c
 *
 *  Created on: Aug 18, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include"ds.h"


void main(int argc, char *argv[])
{


	printf("Hello world\n");

	DemoAVLTree();

}

NODE *root;
NODE *root1;

void DemoAVLTree()
{


	root1 = insert_using_stack(root1,10);
	root1 = insert_using_stack(root1,9);
	root1 = insert_using_stack(root1,8);

	root1 = insert_using_stack(root1,7);
	root1 = insert_using_stack(root1,6);
	root1 = insert_using_stack(root1,5);
	root1 = insert_using_stack(root1,4);
	root1 = insert_using_stack(root1,3);
	root1 = insert_using_stack(root1,2);
	root1 = insert_using_stack(root1,1);
	root1 = insert_using_stack(root1,11);
	root1 = insert_using_stack(root1,12);

	root1 = DeleteNode(root1, 7);
	root1 = DeleteNode(root1, 12);
	root1 = DeleteNode(root1, 9);
	root1 = DeleteNode(root1, 8);
	root1 = DeleteNode(root1, 3);

//	root = insert(root, 10);
//	root = insert(root, 9);
//	root = insert(root, 8);
//	root = insert(root, 7);
//	root = insert(root, 6);
//	root = insert(root, 5);
//	root = insert(root, 4);
//	root = insert(root, 3);
//	root = insert(root, 2);
//	root = insert(root, 1);
//	root = insert(root, 11);
//	root = insert(root, 12);



	preorder(root);
	printf("\n");
	preorder(root1);
	printf("\n");
	 inorder(root);
	 printf("\n");
	 inorder(root1);
		printf("\n");
		 postorder(root);
		 printf("\n");
		 postorder(root1);
		 printf("\n");


}

void preorder(NODE *n)
{
	if(!n)
	{
		return;
	}
	printf("%d [%d], ", n->key, n->h);
	preorder(n->l);
	preorder(n->r);
}



void inorder(NODE *n)
{
	if(!n)
	{
		return;
	}

	inorder(n->l);
	printf("%d [%d], ", n->key,n->h);
	inorder(n->r);
}

void postorder(NODE *n)
{
	if(!n)
	{
		return;
	}

	postorder(n->l);
	postorder(n->r);
	printf("%d [%d], ", n->key, n->h);
}


NODE *CreateNode(int key)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->h = 1;
	temp->key = key;
	temp->r = temp->l = NULL;
	return temp;
}

int height(NODE *n)
{
	if(n)
	return n->h;
	else
		return 0;
}
/*left child - right child*/
int GetBalanceFactor(NODE *node)
{
	return (height(node->l) - height(node->r));
}

NODE *RotateRight(NODE *parent)
{
	NODE *RotateCentre = parent->l; //This is centre of rotation
	NODE *RotCenRightChild = RotateCentre->r; //This is

	RotateCentre->r = parent;
	parent->l = RotCenRightChild;
	parent->h = MAX(height(parent->l), height(parent->r));
	parent->h+=1;
	RotateCentre->h = MAX(height(RotateCentre->l), height(RotateCentre->r));
	RotateCentre->h+= 1;

	printf("RotateRight :RotateCent-> h = %d paretn->h = %d\n",RotateCentre->h,parent->h);

	return RotateCentre;
}

NODE *RotateLeft(NODE *parent)
{
	NODE *RotateCentre = parent->r;
	NODE *RotateCentreLeftChild = RotateCentre->l;

	RotateCentre->l = parent;
	parent->r = RotateCentreLeftChild;

	parent->h = MAX(height(parent->r), height(parent->l));
	parent->h +=1;
	RotateCentre->h = MAX(height(RotateCentre->r), height(RotateCentre->l));
	RotateCentre->h +=1;
	printf(" RotateLeft : RotateCent-> h = %d paretn->h = %d\n",RotateCentre->h,parent->h);

	return RotateCentre;

}

NODE * insert(NODE *node, int key)
{

		if(node == NULL)
		{
			printf("Adding key = %d \n", key);
			return CreateNode(key);
		}
		if(key > node->key)
		{
			node->r = insert(node->r, key);
		}
		else
		{
			node->l = insert(node->l, key);
		}

		/*adjust height of node after insertion*/
		int lh = height(node->l);
		int rh = height(node->r);
		int h = MAX(lh,rh);

        node->h = h + 1;

        printf("K = %d lh = %d rh = %d  h = %d\n",node->key,lh,rh, node->h);
        /*Find the balancing factor of the node*/

        int balance = GetBalanceFactor(node);

        printf("balance = %d \n",balance);
        /*
         * balance > 1 --> insertion happened in left sub child
         * balance < -1 --> insertion on right sub child
         *
         *
         * */
        /*insertion on left child :: Left child of left subtree*/
        if(balance > 1 && key < node->l->key)
        {
        	return RotateRight(node);

        }

        if(balance < -1 && key > node->r->key)
	    {
        	return RotateLeft(node);
	    }

        /*new node is right child of left subtree*/
        if(balance > 1 && key > node->l->key)
        {
        	node->l = RotateLeft(node->l);
        	return RotateRight(node);
        }
        if(balance < -1 && key < node->r->key)
        {

        	node->r = RotateRight(node->r);
        	return RotateLeft(node);

        }
        return node;

}

