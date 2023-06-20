/*
 * kmp.c
 *
 *  Created on: 27-Mar-2017
 *      Author: sansaras
 */

test_kmp()
{
	char txt[] = {'A','B','C','A','C','A','C','A','A','T'};
	char pat[] = {'A','C','A','C','A','A','T'};
	char lps[7] = {0};

	compute_lps(pat,7,lps);
	int j = 0;
	for(j = 0; j<7; j++)
	{
		printf("%c	",pat[j]);
	}
	printf("\n");
	for(j = 0; j<7; j++)
		{
			printf("%d	",lps[j]);
		}

	printf("\n");
	match_pattern(pat, txt, lps, 7, 10);
}


 match_pattern(char pat[], char txt[], char lps[], int patl, int txtl )
 {

	 int i = 0;
	 int j = 0;
	 while(i < txtl)
	 {

		 if(txt[i] == pat[j])
		 {
			 i++;
			 j++;

		 }
		 if(j == patl)
		 {
		 	printf("match found at i = %d\n", i-j);
		 	j = lps[j-1];
		 }
		 else
		 {
			 while(j < patl && txt[i] != pat[j])
			 {
				 if(j != 0)
				 {
					 j = lps[j-1];
				 }
				 else
				 {
					 i++;
				 }
			 }
		 }

	 }

 }

void compute_lps(char pat[],int N, char lps[])
{
	int i = 0, len = 0;
	lps[i] = len;
	i = 1;
	while(i < N)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}

		}
	}
}


/*
l[i] = { i including

		i excluding..}


		*/
