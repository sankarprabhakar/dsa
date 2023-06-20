/*
 * endian.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */


void printf_endian();
#if 1
void endian_main()
{
	print_endian();
}
#endif
print_endian()
{
	int a = 0x0a0b0c0d; //LSB or MSB
	/*	LSB in big address is big-endian
	 *  LSB in small address is little-endian
	 *
	 * --------------------
	 *|1000|1001|1002|1003|
	 *|----|----|----|----|
	 *|0x0A|0x0B|0x0C|0x0D| --> Big Endian
	 *|-------------------|
	 *|0x0D|0x0C|0x0B|0x0A| --> Little Endian
	 *|-------------------|
	 *
	 *
	 */

	int c = 0x01;
	char *d = (char *)&c;
	char *b = (char *)&a; //

	printf("INP(abcd) = %x  inp(0x01) = %x\n",*b, *d);//prints d for little and a for big endiaan
int i =0;
	for( i=0;i<4;i++)
	{
		printf("%x",b[i]);

	}
}
