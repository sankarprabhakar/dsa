/*
 * main.c
 *
 *  Created on: Dec 17, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#include"hashapi.h"

#define PRINT_ERR(x) if(x<0)printf("ERR in inserting\n");

void main()
{
	HASH_TABLE_NODE *ht = CreateHashTable(5);


	PRINT_ERR(insert(ht,0,1))
	insert(ht,1,3);
	insert(ht,5,2);

	insert(ht,4,4);
	PRINT_ERR(insert(ht,1,7))
	insert(ht,7,20);
	PRINT_ERR(insert(ht,8,20))

	search(ht,1);

	print(ht);

	delete(ht,5);
	print(ht);
}
