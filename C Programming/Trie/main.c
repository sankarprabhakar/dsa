/*
 * main.c
 *
 *  Created on: Jan 9, 2017
 *      Author: sankarsa
 */


#include<stdio.h>

#include"trie.h"

TRIE_NODE *head = NULL;
int main()
{
	int num = 0;
	int i = 0;
	char operation[1024] = {0};
	char operator[1024] = {0};


	//printf("Enter number opeartions\n");
	scanf("%d", &num);
	for(; i<num; i++)
	{
		scanf("%s", operation);
		printf("%s", operation);
		if(strcmp(operation, "add") == 0)
		{
			scanf("%s", operator);
		//	printf("%s", operator);
			insertString(&head, operator);


		}
		else if(strcmp(operation,"find") == 0)
		{
			scanf("%s", operator);
			//printf("%s", operator);
			printf("%d", searchOccurance(head,operator));
		}
		else
		{
			printf("invalid operator");
			return -1;
		}

	}

}
