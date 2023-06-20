/*
 * check_bst.c
 *
 *  Created on: Jan 8, 2017
 *      Author: sankarsa
 */


/*
 * For the purposes of this challenge, we define a binary search tree to be a binary tree with the following ordering properties:
 * 1. The value of every node in a node's left subtree is less than the data value of that node.
 * 2. The value of every node in a node's right subtree is greater than the data value of that node.
 *
 * Given the root node of a binary tree, can you determine if it's also a binary search tree?
 *
 * Complete the function in your editor below, which has 1 parameter: a pointer to the root of a binary tree.
 * It must return a boolean denoting whether or not the binary tree is a binary search tree.
 * You may have to write one or more helper functions to complete this challenge.
 * Note: A binary tree is not a binary search if there are duplicate values.
 *
 *
 *
 * */

#include<stdio.h>
#if 0
typedef struct Node{
      int data;
      Node* left;
      Node* right;
}Node;

int checkBST(Node* root) {

	return isBST(Node *root, NULL);

}


/*inorder traversal and checking the data is intact... the previous will store the
 * data previously visited*/
int isBST(Node *root, Node **prev)
{

	if(root)
	{
	if(!isBST(root->left), prev)
	{
		return 0;
	}

	if(*prev != NULL && (*prev)->data <= root->data)
		return 0;
	prev = root;
	return isBST(root->right, prev);
	}
	return 1;

}


#endif
