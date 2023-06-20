/*
 * max_continous_subsequence.c
 *
 *  Created on: Aug 17, 2016
 *      Author: sankarsa
 */

#define MAX(A, B) (A)>=(B)?(A):(B)
/*
 * total array size: n
 * Array name : A
 *  - A[i] is considered only if S > 0; else a new sub-sequence starts from next element.
 *
 *  S[i] = Max(S[i-1] + A[i], A[i]);
 *
 * */


int A[9] = {0,-2,-1,4,-1,-2 ,1,5,-3};

int S[9] = {0};

int main_x(int argc, char *argv[]){
	int i = 1, max = S[0], s = 1, l = 1, ls= 1;
	for(i = 1; i<= 8 ; i++)
	{
		int j =  MAX((S[i-1] + A[i]), A[i]);
		S[i] = j;
		if(S[i] <= 0 )
		{
			s = i;
		}
		if(max < S[i])
		{
			ls = s;
			l = i;
			max = S[i];
		}

	}
	printf("%d to %d\n", s, l-1);

	  //  int max = S[i]; int s = 1, l=1;
	    for(i= 1; i<= 8 ; i++)
		{
			printf("S[%d] = %d\n",i,S[i]);

			if(max < S[i])
			{
				max = S[i];
				l = i;

			}
			if(S[i] <= 0)
			{
				s=i;
			}
		}
	    printf("%d to %d\n", s, l-1);

}

