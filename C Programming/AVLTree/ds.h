/*
 * ds.h
 *
 *  Created on: Aug 18, 2016
 *      Author: sankarsa
 */

#ifndef DS_H_
#define DS_H_

#define MAX(A, B) ((A)>=(B)?(A):(B))
typedef struct AVL_NODE
{
	 int key; //value
	 struct AVL_NODE *r; //right sub tree
	 struct AVL_NODE *l; //left sub tree
	 int h; //height

}NODE;

NODE *insert_using_stack(NODE *node,int key);
NODE *CreateNode(int key);

int GetBalanceFactor(NODE *node);

void DemoAVLTree(void);
NODE * insert(NODE *node, int key);
void preorder(NODE *n);

NODE *RotateRight(NODE *parent);
NODE *RotateLeft(NODE *parent);


int height(NODE *n);
void inorder(NODE *n);
void postorder(NODE *n);

#endif /* DS_H_ */
