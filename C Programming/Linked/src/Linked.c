/*
 ============================================================================
 Name        : Linked.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int d;
	struct node *l;
}NODE;

NODE *insert(NODE **root, int data);
void printReverse(NODE *root);
NODE *createNode(data);
int  printLength(NODE *root);
NODE *deleteNode(NODE **root, int data);
void printMiddleNode(NODE *root);
void printMiddleNode_bycounter(NODE *root, int split);
void printList(NODE *root);
void removeDuplicates(NODE *root);
void reverseLinkedList_Iterative(NODE **root);
NODE * reverseLinkedList_Recursive(NODE *cur, NODE **root);
NODE * reverseLinkedList_Recursive_1(NODE *cur, NODE *next);
NODE *root = NULL;
int main(void) {
	puts("!!!Hello World!!!\n"); /* prints !!!Hello World!!! */
	insert(&root,10);
	insert(&root,5);
	insert(&root,5);
	insert(&root,5);
	insert(&root,5);
	insert(&root,5);
	insert(&root,4);
	insert(&root,4);
	insert(&root,25);
	insert(&root,25);
	insert(&root,10);
	insert(&root,3);
	insert(&root,99);
	deleteNode(&root,3);
	deleteNode(&root,99);
	/*Print*/
	printf("Printing the linked list\n");
	printList(root);

    /*Printing reverse*/
	printf("\nPrinting the linked list reverse\n");
	printReverse(root);
	printf("\nLength = %d \n",printLength(root));
	/*Print middle of linked list*/
	printf("Printing the middle of list\n");
	printMiddleNode(root);
	printf("Printing the middle of list by counter\n");
	printMiddleNode_bycounter(root,2);
	printf("Remove duplicates \n");
	removeDuplicates(root);
	printf("Without duplicates\n");
	printList(root);
	printf("Reverse list\n");
	reverseLinkedList_Iterative(&root);
	printf("Printing the linked list(after reversing)\n");
	printList(root);
	printf("Reverse list\n");
	NODE * last = reverseLinkedList_Recursive(root, &root);
	last->l = NULL; //ending the last node.
	printf("Printing the linked list(after reversing)\n");
	printList(root);
	printf("Reverse list 1\n");
	root = reverseLinkedList_Recursive_1(root, 0);
	printf("Printing the linked list(after reversing)\n");
	printList(root);
	// try reversing


}
//When to use the double pointer ?

NODE *insert(NODE **root, int data)
{

	if(root == NULL) return NULL;
	if(*root == NULL)
	{
		*root = createNode(data);
		return *root;
	}
	NODE *temp = *root; NODE *prev = NULL;
	while(temp != NULL && temp->d < data)
	{
		prev = temp;
		temp = temp->l;
	}
	if(prev == NULL && temp != NULL)
	{
		*root = createNode(data);
		(*root)->l = temp;
	}
	else
	{
		prev->l = createNode(data);
		prev->l->l = temp;
	}

    return *root;
}

NODE *deleteNode(NODE **root, int data)
{
	if(NULL == root) return NULL;
	else if(NULL == *root) return NULL;
	NODE *temp = *root;
	NODE *prev = NULL;
    while(temp != NULL && temp->d != data)
    {
    	prev = temp;
    	temp = temp->l;
    }
    if(NULL ==temp)
    {
    	printf("Data not found");
    	return NULL;
    }
    else if(temp == *root)
    {
    //	NODE *nxt = (*root)->l;
    	*root = temp->l;
    	free(temp);
    }
    else
    {
    	prev->l = temp->l?temp->l->l:NULL;
    	free(temp);
    }
    return *root;

}

void printList(NODE *root)
{
	if(root == NULL)
		return;
	while(root!=NULL)
	{
		printf("%d -> ",root->d);
		root = root->l;
	}
	return;
}

void printReverse(NODE *root)
{
	if(root == NULL)
		return;
	printReverse(root->l);
	printf("%d-",root->d);
	return;
}

int  printLength(NODE *root)
{
	if(root == NULL)
		return 0 ;
	return printLength(root->l) + 1;
}
NODE *createNode(int data)
{
	NODE *s = malloc(sizeof(NODE));
	s->d = data;
	s->l = NULL;
	return s;
}

/*Print middle node of a linked list using the fast/slow */
void printMiddleNode(NODE *root)
{
	if(NULL == root) return;
	NODE *fast = NULL, *slow = NULL;
	fast = slow = root;
	while (fast!=NULL && fast->l != NULL && fast->l->l != NULL)
	{
		fast = fast->l->l;
		slow = slow->l;
	}
	printf("\nMid data  = %d \n",slow->d);
}

/*Print middle node of a linked list using the fast/slow */
void printMiddleNode_bycounter(NODE *root, int split)
{
	if(NULL == root) return;
	int counter = 1; //0 to get floor value of len/2
	NODE *temp = root;
	NODE *slow = root;

	while (temp->l !=NULL)
	{
		temp = temp->l;
		counter++;
		if(counter%split == 0)
			slow = slow->l;
	}
	printf("\nMid data  = %d \n",slow->d);
}
/*Remove duplcates from sorted linked list*/
void removeDuplicates(NODE *root)
{
	NODE *cur = root;
	NODE *pre = root;
	NODE *temp = NULL;
	if(NULL == cur) return;
	while(cur!= NULL && cur->l !=NULL)
	{
		cur = cur->l;
		while(cur != NULL && pre->d == cur->d)
		{
			pre->l = cur->l;
			temp = cur;
			cur = cur->l;
			free(temp);
		}
		pre = cur;
	}
}

void reverseLinkedList_Iterative(NODE **root)
{
	NODE *current,*prev,*next;
	prev = next = NULL;
	current = *root;
	if (current == NULL) {printf("Empty \n"); return;}
	while(current != NULL)
	{
		next = current->l;
		current->l = prev;
		prev = current;
		current = next;
	}
	*root = prev;
}

NODE * reverseLinkedList_Recursive(NODE *cur, NODE **root)
{
	if (cur  -> l == NULL)
	{
		*root = cur;
	}
	else
	{
		reverseLinkedList_Recursive(cur->l, root);
		cur -> l -> l = cur;
		return cur;
	}
}

// Return the head pointer
NODE * reverseLinkedList_Recursive_1(NODE *cur, NODE *next)
{
	if(cur == NULL) return NULL;
	NODE *ret = NULL;
	if (cur  -> l != NULL)
	{
		ret = reverseLinkedList_Recursive_1(cur->l, cur);
	}
	else
	{
		ret = cur;

	}
	cur -> l = next;
	return ret;
}
