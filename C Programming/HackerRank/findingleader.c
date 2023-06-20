/*
 * findingleader.c
 *
 *  Created on: Mar 5, 2017
 *      Author: sankarsa
 */

#include<stdio.h>
typedef struct best
{
	char best[1024];
	int longest;
}BEST;

test_longest()
{

	int tc = 0;
	char *s = NULL;
	int len = 0;
	char *tst = NULL;
	int tlen = 0 , tn = 1, tno = 0;
	//printf("Hello");
	getline(&tst,&tlen, stdin);
	tno = atoi(tst);
	free(tst);
	BEST bt[tno];
	memset(bt, 0 , sizeof(BEST) * tno);

while(tn <= tno)
{

	s = NULL;
	len = 0;
	getline(&s, &len, stdin);
	int i = atoi(s);
	free(s);

	while(i != 0)
	{
		s = NULL;
		len = 0;
		getline(&s, &len, stdin);
		finding_the_best(s, &bt[tn-1]);
		i--;
		free(s);
	}
	tn++;
}
int i;
for( i = 1; i <= tno; i++)
printf("Case #%d: %s\n",i, &bt[i-1].best);


}
#if 0

int getdelim(char **linep, int *n, char delimit, FILE *fp)
{

	char c = 0, i = 0;
	if(!linep || !n || !fp)
	{
		return -1;
	}
	if(*linep == NULL)
	{
		if(NULL == (*linep = malloc(*n = 128)))
		{
			*n=0;
			return -1;
		}
	}
	while((c = fgetc(fp)) != EOF)
	{
		if(i + 1 >= *n)
		{
			*linep = realloc(*linep, *n+128);
			if(*linep == NULL){
				return -1;
			}
			*n+=128;
		}
		if(c == delimit)
		{
			(*linep)[i] = '\0';
			break;
		}
		else
		{
			(*linep)[i++] = c;
		}

	}
	return !i && c == EOF ? -1 : i;
}

int getline(char **linep, int *n, FILE *fp)
{
	return getdelim(linep,n, '\n', fp);

}
#endif
int finding_the_best(char *ip, BEST *best)
{

	int i =0;
	char alp[26] = {0};
	int count =0;
	while(ip[i] != '\0')
	{
		if(ip[i] == ' ')
		{
			i++;
			continue;

		}
		int indx = ip[i] - 'A';

		(alp[indx] != 1)?(alp[indx] = 1, count++):0;
		i++;
	}

	printf("%s %d\n",ip,count);

	if(best->longest < count || (best->longest ==  count && strcmp(ip, best->best) < 0))
	{
		best->longest = count;
		strcpy(best->best, ip);
	}

}
