/*
 * naive_patternsearch.c
 *
 *  Created on: Mar 7, 2017
 *      Author: sankarsa
 */
#include<stdio.h>

void pattern_search_test()
{

	search_pattern("BAABBAABBAAB","AAB");
}

search_pattern(char *txt, char *pat)
{

	int i = 0, j =0;
	while(txt[i] != '\0')
	{
		j = 0;
		while(pat[j] != '\0')
		{
			if(txt[i+j] == '\0')
			{
				return 1;
			}
			else if (txt[i+j] != pat[j])
			{
				break;
			}
			if(pat[j+1] == '\0')
			{

				printf("pattern found at %d \n", i);
				i=i+j;//skipping
			}
			j++;
		}

		i++;
	}

}

