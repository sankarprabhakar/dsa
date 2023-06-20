/*
 * longest_common_subsequence.c
 *
 *  Created on: Dec 20, 2016
 *      Author: sankarsa
 */

#define MAX_IN_2(x,y) (x)>(y)?(x):(y)


int longest_common_subsequence(char *s1, char *s2)
{
	int l1 = strlen(s1) + 2;
	int l2 = strlen(s2) + 2;
	int i = 0, j = 0;
	char *lcs = (char *)malloc((l1 *l2) * sizeof(int));
	memset(lcs, 0, (l1 *l2) * sizeof(int));
	char (*lcs_arr)[l1] = lcs;
	for(j= 2; j<l1; j++)
	{

		lcs_arr[0][j] = s1[j-2];
		lcs_arr[1][j] = 0;
	}
	for(i= 2; i<l2; i++)
	{

		lcs_arr[i][0] = s2[i-2];
		lcs_arr[i][1] = 0;
	}

	for(i = 2; i<l2; i++ )
	{
		for(j=2;j<l1;j++)
		{
			if(lcs_arr[0][j] == lcs_arr[i][0])
			{
				lcs_arr[i][j] = lcs_arr[i-1][j-1] + 1;
			}
			else
			{
			    lcs_arr[i][j] = MAX_IN_2(lcs_arr[i-1][j], lcs_arr[i][j-1]);
			}
		}
	}

print_2d_array(lcs, l1,l2);

}
