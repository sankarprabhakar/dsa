/*
 * socket_utility.c
 *
 *  Created on: Jul 28, 2016
 *      Author: sankarsa
 */
#include<stdio.h>

#include<arpa/inet.h>
int num1 = 0x01;
int *b = &num1;

void main(int argc, char*argv[])
{

	int num = 0x1;
	int *a = &num;
	char *c = (char *)&num;

	printf("%x %x %x %x\n",c[0],c[1],c[2],c[3]);

	printf("endian = %s\n", (((*(char*)a) & 0x1) == 0)?"Big":"Little");
	printf("G endian = %s\n", (((*(char *)b) & 0x1) == 0)?"Big":"Little");


	int d = htonl(0x01020304);
	int d1 = my_htonl(0x01020304);
	printf("HTONL = %x  D1 = %x\n", d,d1);

	int p = 0;
	inet_pton(AF_INET, "1.2.3.4",&p); //this funciton does string to decimal  + "hton"

	printf("converted ip address  = %x \n",p);

	char nw[100];
  inet_ntop(AF_INET,(void *) &p,&nw ,100); // host addres to string
	printf("Presentation fomat = %s \n",nw);


}

int my_htonl(int a)
{
	int num = 0x01;
	int b = 0;
	char *c = &num;
	if(*c == 0)
	{
		return a;
	}
	else
	{
		int i = 0;
		while(i < 4)
		{
		b = b << 8;
		b |= a & 0xFF;
		//printf("%x \n", b);
		a = a >> 8;
		i++;
		}
	}
//	printf("%x \n", b);
	return b;
}
