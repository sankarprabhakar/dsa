/*
 * characterinstring.c
 *
 *  Created on: Dec 8, 2016
 *      Author: sankarsa
 */
#include<stdio.h>

int print_char_in_string(const char *input)
{
	int count[52] = {0}, i = 0;
	if(NULL != input)
	{
		while(input[i] != '\0')
		{
			if(input[i] >= 'a' && input[i] <= 'z')
			count[input[i] - 'a']++;
			else if(input[i] >= 'A' && input[i] <= 'Z')
			count[26 + (input[i] - 'A')]++;
			i++;
		}

	}
	for(i =0 ; i <=51; i++)
	{
		if(count[i] != 0)
		printf("%c \t %d\n", i<26?(i + 'a'):(i-26 + 'A'),count[i]);
	}
}
