/*
 * longest_common_subsequence.c
 *
 *  Created on: Dec 20, 2016
 *      Author: sankarsa
 */

#define MAX_IN_2(x,y) (x)>(y)?(x):(y)
#define MAX_IN_3(x,y,z) (x)>(y)?((x)>(z)?(x):(z)):((y)>(z)?(y):(z))

int longest_common_substring(char *s1, char *s2)
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

	int max = 0, start = -1, end = -1, cur_l_start  = -1, cur_l_end = -1,end_detected=1;
	for(i = 2; i<l2; i++ )
	{
		for(j=2;j<l1;j++)
		{
			if(lcs_arr[0][j] == lcs_arr[i][0])
			{
				lcs_arr[i][j] = lcs_arr[i-1][j-1] + 1;
				if(lcs_arr[i-1][j-1] == 0)
				{
					//cur_l_start = start;
					end_detected = 0;
					start = i-2;
				}
			}
			else
			{
				lcs_arr[i][j] = 0;
						//lcs_arr[i][j] = MAX_IN_3(lcs_arr[i-1][j-1],lcs_arr[i-1][j], lcs_arr[i][j-1]);
			}
			if(max < lcs_arr[i][j])
			{

				//end = i-2;
				cur_l_start = i;
				cur_l_end = j;

			}

			max = MAX_IN_2(max, lcs_arr[i][j]);
		}
	}

print_2d_array(lcs, l1,l2);
printf("max = %d  %d %d \n", max, cur_l_start, cur_l_end);
i = cur_l_start - max +1;
j = cur_l_end - max +1;
int w = 0;
for(w = 0; w<max; w++)
{
	//if(lcs_arr[i+2][j+2] != 0)
	printf("%c",lcs_arr[0][j]);
	i++; j++;
}
printf("\n");
}
