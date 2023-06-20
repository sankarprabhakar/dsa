/*
 * edit_distance.c
 *
 *  Created on: Dec 20, 2016
 *      Author: sankarsa
 */

#include<stdio.h>


#define MAX_IN_3(x,y,z) (x)>(y)?((x)>(z)?(x):(z)):((y)>(z)?(y):(z))
#define MIN_IN_3(x,y,z) (x)<(y)?((x)<(z)?(x):(z)):((y)<(z)?(y):(z))

int edit_distance(char *s1, char*s2)
{
	if(s1 == NULL || s2 ==NULL)
	{
		return -1;
	}

	int l1 = strlen(s1) + 2;//one for string and another for index 0
	int l2 = strlen(s2) + 2; //one for string and another for index 0

	char *dp_array = (char *)malloc((l1 * l2) * sizeof(int));
	memset(dp_array,0,(l1 * l2) * sizeof(int));
	char (*ed_array)[l1] = dp_array;

	/*filling the string*/

	int i = 0, j =0;
	for(j = 2; j<l1; j++)
	{
		ed_array[0][j] = (int)s1[j-2];
		ed_array[1][j] = j-1;
	}

	for(i = 2; i<l2; i++)
	{
			ed_array[i][0] = (int)s2[i-2];
			ed_array[i][1] = i-1;
	}

//	print_2d_array(dp_array, l1,l2);
	int dis1 = 0, dis2 = 0, dis3 = 0;
	for(i = 2; i < l2; i++)
	{
		for(j = 2; j < l1; j++)
		{
			if(ed_array[i][0] == ed_array[0][j])
			{
				 ed_array[i][j] = ed_array[i-1][j-1];
			}
			else
			{
				 dis1 = ed_array[i-1][j-1] + 1;
				 dis2 = ed_array[i-1][j] + 1;
				 dis3 = ed_array[i][j-1] + 1;

				 ed_array[i][j] = MIN_IN_3(dis1, dis2, dis3);
			}

		}

	}
	print_2d_array(dp_array, l1,l2);

}

print_2d_array(char *q,int l1,int l2)
{
	char (*ed_array)[l1] = q;

	int i = 0, j = 0;

	for(i = 0; i <l2; i++)
	{
		for(j = 0; j<l1; j++)
		{
			if(i ==0 || j == 0)
			printf("%3c ", ed_array[i][j]);
			else
			printf("%3d ", ed_array[i][j]);

		}
		printf("\n");
	}
}

