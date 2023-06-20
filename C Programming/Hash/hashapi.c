/*
 * hashapi.c
 *
 *  Created on: Dec 17, 2016
 *      Author: sankarsa
 */


#include<stdio.h>
#include "hashapi.h"
int hashkey = 1;
HASH_TABLE_NODE *CreateHashTable(int size)
{

	hashkey = size;
	HASH_TABLE_NODE *tab = (HASH_TABLE_NODE *) malloc(size * sizeof(HASH_TABLE_NODE));
	memset(tab, -1, size * sizeof(HASH_TABLE_NODE));
	if(!tab)
    return NULL;
	return tab;
}

int hashfun(int key)
{
	return key%hashkey;
}



int insert(HASH_TABLE_NODE *ht, int key, int data)
{
	if(!ht)
	return 0;


	int hashed_key = hashfun(key);
	int first_key = hashed_key;
	while( ht[hashed_key].key != -1)
	{
		if(ht[hashed_key].key == key)
		{
			break;//this key is already present; the overwrite the data
		}

		hashed_key++;
		hashed_key %= hashkey;
		if(first_key == hashed_key)
		{
			return -1;
		}

	}

	ht[hashed_key].key = key;
	ht[hashed_key].data = data;

	return 1;
}


int delete(HASH_TABLE_NODE *ht, int key)
{
	int hash_key = hashfun(key);
	int first_key = hash_key;
	while(ht[hash_key].key != key)
	{

		hash_key++;
		hash_key %= hashkey;
		if(hash_key == first_key)
		{
			return -1;
		}
	}

	ht[hash_key].key  = -1;
	ht[hash_key].data  = 0;

    return 1;
}



int search(HASH_TABLE_NODE *ht, int key)
{
	int hash_key = hashfun(key);
	int first_key = hash_key;
	while(ht[hash_key].key != key)
	{

			hash_key++;
			hash_key %= hashkey;
			if(hash_key == first_key)
			{
				return -1;
			}
	}
	return ht[hash_key].data;
}

int print(HASH_TABLE_NODE *ht)
{
	int hash_key = 0;
	while(hash_key < hashkey)
	{
		printf("(%d-%d)\n", ht[hash_key].key, ht[hash_key].data);
		hash_key++;
	}

}
