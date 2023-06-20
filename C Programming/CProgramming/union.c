/*
 * union.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */
#if 1
void union_main()
{
    test_union();
	//test_struct_union();
    //test_compare_structures();//Not a valid case
    test_union_bitfields();

}
#endif
typedef union u1
{
	int a; char b;
}UNION1;

test_union()
{
	UNION1 a;
	a.b='a';
	printf("Size of union - %d\n", sizeof(a));
	printf("a.a - %d\n", a.a);
	printf("a.b- %c\n", a.b);

}

typedef struct u2
{
	int a;
	union{
		int a;
		char b;
	}u;
	char b;
}S1;

test_struct_union()
{
	S1 s;
	printf("Sizeof struct = %d\n",sizeof(s));//12
    s.u.a = 77;
}

test_compare_structures()
{
	typedef struct A {
		int a;
	}mystruct;
	mystruct A1 = {55};
	mystruct A2 = {55};
	mystruct A3 = {55};
	//mystruct A4 = &A3; //invalid init  - compiler error
	mystruct * A4 = &A3;

#if 0
	if(A1 == A2) //Compilation error
		printf("Comparable and equal\n");
#endif

	if (&A3 == A4)
		printf("It is equal \n");

}

typedef union bit_fields
{
	int a:1;
	char c:1;
	int d;


}BIT_FIELD;
test_union_bitfields()
{
	BIT_FIELD bf1;
	printf("Size of bit field = %d \n", sizeof(bf1));
	bf1.d=88;
	printf("Value of d = %d \n", bf1.d);
	bf1.c=4;
	printf("Value of C = %d \n", bf1.c);
	bf1.a=1;
	printf("Value of a = %d \n", bf1.a);// why is it giving -1

}
