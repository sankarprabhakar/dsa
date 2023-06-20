#include<stdio.h>

/*
 * permute(str, k, n)
 * k == n; print str..
 * else
 * for i from k to n.
 * swap a[i] & a[k]
 *  perm(str,k+1,n)
 *  swap a[i] & a[k]
 *
 * */


swap(char *a, char *b)
{
	char t = *b;
	*b = *a;
	*a = t;

}
static count = 0;
test_permute()
{
	char s[] = "ABC";
	permute(s,0,strlen(s), 3);
	printf("count = %d \n", count);
}

permute(char *str, int k , int n, int len)
{

	//printf("***New frame*** k = %d\n", k);
	if(k == len)
	{
		count++;
		int j;
		//printf("%s\n",str);
		for(j = 0  ;j < len;j++)
		{
			printf("%c", str[j]);
		}
		printf("\n");
	}
	else
	{
		int i = 0;
		for(i = k; i<n ; i++)
		{
			swap(&str[i],&str[k]);
			//printf("-----%s----- i = %d k = %d n = %d\n",str,i,k,n);
			permute(str, k+1,n, len);
			swap(&str[i],&str[k]);
		//	printf("*****%s***** i = %d k = %d n = %d\n",str,i,k,n);
		}
	}
	//printf("***One Frame Ends ***\n");
}


/*
 * -combination
 *
 *
 *
 *
 * */
//int count = 0;
test_comibation()
{
	char B[] = "ABCD"; //4C1 + 4C2 + 4C3 +4C4 -- 4 + 6 + 4 + 1
	int A[] = {0,0,0,0};
	count = 0;
	combination(A,B,0,3);
	printf("Count = %d \n", count-1);
}


combination(int A[], char B[], int k, int n)
{

	if(k == n)
	{
		count+=2;
		A[k] = 0; printArray(A, B, n);
		A[k] = 1; printArray(A, B, n);
		return;
	}
	A[k] = 0;
	combination(A,B, k+1, n);
	A[k] = 1;
	combination(A,B, k+1, n);

}


printArray(int A[], char B[], int n)
{
 int i = 0;
 for(i = 0; i<=n ; i++)
 {
	 if(A[i] == 1)
	 {
		 printf("%c",B[i]);
	 }
 }
 printf("\n");
}
