/*
 * binarytree.h
 *
 *  Created on: Jun 10, 2016
 *      Author: sankarsa
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_


#define MAX(A, B) (A)>=(B)?(A):(B)

typedef struct node
{
	struct node *l;
	struct node *r;
	int visited;
	int value;
	int r_thread;
	int l_thread;
}Node;


Node *root;

Node* insert(Node *n,int v);
void inorder(Node *n);
void preorder(Node *n);
void postorder(Node *n);
int height(Node *n);

Node * SearchNode(Node *n,int val, Node **p);
Node *FindInorderSucessor(Node *n, Node **p);
void Inorder_Pred_successor(Node *root, Node **p, Node **s, int key);
Node * Search_without_Recursion(Node *root, int key);
void DeleteBTree(Node *root);
int Diameter(Node *root);
int DiameterMod(Node *root, int *height);
int height_using_levelorder(Node *root);
void MorrisTraversal_inorder(Node *root);


Node * CreateTree(void);
void FindMinMax(Node *root, int *min, int *max);
void test_binary_utils(void);


int findElement_recursive(Node *root, int x);
#endif /* BINARYTREE_H_ */
