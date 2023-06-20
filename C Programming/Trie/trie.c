/*
 * trie.c
 *
 *  Created on: Jan 9, 2017
 *      Author: sankarsa
 */

#include<stdio.h>
#include<strings.h>
#include"trie.h"






TRIE_NODE *trie;




TRIE_NODE *getTrieNode()
{
	TRIE_NODE *new = malloc(sizeof(TRIE_NODE));
	new->prefix_count = 0;
	new->leaf_node = 0;
	memset(new->character, NULL, MAX_CHARACTER*sizeof(TRIE_NODE *));
	return new;
}


int insertString(TRIE_NODE **head, char *input)
{
	int length = strlen(input);

	if(*head == NULL)
	{
		*head = getTrieNode();
	}
	int i = 0;
	TRIE_NODE *temp = *head;
	for(; i<length; i++)
	{
		int index = input[i] - 'a';
		if(temp->character[index] == NULL)
		{
			temp->character[index] = getTrieNode();

		}
		temp = temp->character[index];
		temp->prefix_count++;

	}
	temp->leaf_node = 1;
}


int searchString(TRIE_NODE *head, char *input)
{
	int length = strlen(input);
	if(head == NULL)
	{
		return -1;
	}
	int i = 0;
	TRIE_NODE *temp = head;
	for(;i<length;i++)
	{
		int index = input[i] - 'a';
		if(temp->character[index] == NULL)
		{
			printf("Not found\n");
			return -1;
		}
		temp = temp->character[index];
	}
	if(temp->leaf_node == 1)
	{
		printf("Word found\n");
		return 0;
	}
	else
	{
		printf("Not found");
		return -1;
	}
}



int searchOccurance(TRIE_NODE *head, char *input)
{
	int  count = 0;
	int length = strlen(input);
	if(head == NULL)
	{
		return -1;
	}
	int i = 0;
	TRIE_NODE *temp = head;
	for(;i<length;i++)
	{
		int index = input[i] - 'a';
		if(temp->character[index] == NULL)
		{
			printf("Not found\n");
			return 0;
		}
		temp = temp->character[index];
	}
	return temp->prefix_count;
//	if(temp->leaf_node == 1)
//	{
//		printf("Word found\n");
//		return 0;
//	}
//	else
//	{
//		printf("Not found");
//		return -1;
//	}
}
