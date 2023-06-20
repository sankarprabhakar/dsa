/*
 * longest_palindrome_sequence.c
 *
 *  Created on: Dec 26, 2016
 *      Author: sankarsa
 */

#include<stdio.h>
#define MAX_IN_2(x,y) (x)>(y)?(x):(y)

int *lps1 = NULL;

int longest_palindrom_sequence(int i, int j, char *s)
{
//printf("%d%d\n",i,j);
	static int count =0;
	count++;
	printf("%d\n",count);
	if(lps1 == NULL)
	{
		lps1 = malloc(strlen(s) *strlen(s) * sizeof(int));
		memset(lps1, -1, strlen(s)*strlen(s)*sizeof(int));
	}
	int (*lps)[strlen(s)] = lps1;
	if(lps[i][j] != -1)
	{
		return lps[i][j];
	}
	if(i == j)
	{
		lps[i][j] = 1;
		return lps[i][j];
	}
	else if((j == (i+1)) && (s[i] != s[j]))
	{
		lps[i][j] = 1;
		return lps[i][j];
	}
	else if((j == (i+1)) && (s[i] == s[j]))
	{
		lps[i][j] = 2;
		return lps[i][j];
	}
	else if(s[i] == s[j])
	{
		lps[i][j] = 2 + longest_palindrom_sequence(i+1, j-1, s);
		return lps[i][j];
	}
	else
	{
		lps[i][j] = MAX_IN_2(longest_palindrom_sequence(i+1, j,s),longest_palindrom_sequence(i,j-1,s));
		return lps[i][j];
	}
}
