/*
 * structures.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */

void test_bits_fields_of_structure();
void test_size_of_structure(void);
#if 1
void main_struct()
{
	//test_pass_return__assign_structure();
	//test_bits_fields_of_structure();
	//test_size_of_structure();
	test_struct_hack();
	test_struct_qno10();
	test_structure_designated_init_q11();
}

#endif
typedef struct mystruct
{

	int a;
}MYSTRUCT;


MYSTRUCT fun1(MYSTRUCT s, MYSTRUCT *s1);
test_pass_return__assign_structure()
{
	MYSTRUCT s;
	s.a = 55;
	MYSTRUCT s2 = fun1(s, &s);
	printf("SA = %d\n",s.a);
	printf("S->retval->A = %d\n",s2.a);

}


MYSTRUCT fun1(MYSTRUCT s, MYSTRUCT *s1)
{
	printf("what we got from S.a = %d %d \n",s.a, s1->a);
	/*s is copy of s in the caller*/
	MYSTRUCT s3;
	printf("S.a = %d\n",s.a);
	s.a=567;
	//s1->a = 568;
	s3 = s; //deep copy of structures is allowed
	return s3; //deep copy of structure members happens to the caller
}

/*bit wise selection of a structure*/

typedef struct mystruct2
{
	unsigned int a:1;
	unsigned int b:2;
	unsigned int c:4;
}MYSTRUCT2;

void test_bits_fields_of_structure()
{
	MYSTRUCT2 m1;
	printf("size of m1 = %d \n", sizeof(m1));
	m1.a = 1;
	m1.b = 3;
	m1.c = 15;

	printf("m1.a = %d \n",m1.a);
	printf("m1.b = %d \n",m1.b);
	printf("m1.c = %d \n",m1.c);
}
//#pragma pack(4)
typedef struct mystruct3
{
	 char a; //4
	 int b;//4
	 char c;//4 total - 12
}MYSTRUCT3;

typedef struct mystruct4
{
	 char a; //1
	 char c; //1
	 int b; //4 --> total 8 bytes

}MYSTRUCT4;

void test_size_of_structure(void)
{
	MYSTRUCT3 s;
	MYSTRUCT4 s2;

	printf("Size of MYSTRUCT3 is = %d\n",sizeof(s));
	printf("Size of MYSTRUCT4 is = %d\n",sizeof(s2));
}

/*******************************************************************/

test_struct_hack()
{
	struct s
	{
		int id;
		int age;
		char name[0];

	}y;
	printf("sizeof y = %d\n",sizeof(y));

	struct s *p = malloc(sizeof(y) + sizeof(char) * 10);
	p->id = 100;
	p->age = 99;
	strcpy(p->name, "sankar");
	//printf("value of namefile is %s", );

}


/***********************************************************************/

test_struct_qno10()
{
	typedef struct structc_tag
	{
	   char        c;//1+3 = 4
	   double      d; // 8 + 4
	 //  char 		e;
	   int         s; // 4

	} structc_t;

	typedef struct struct3c_tag
	{
	   char        c;
	   char        d;
	   char        e;

	} struct3c_t;


	typedef struct structa_tag
	{
	   char        c;
	   short int   s;
	   short int   d;
	   char        e;
	} structa_t;

	structc_t x;
	structa_t y;
	struct3c_t z;
	printf("sizeof x is %d\n",sizeof(x));

	printf("Address c = %d\n", &(((structc_t *)0)->c)); //0
	printf("Address d = %d\n", &(((structc_t *)0)->d)); //8
//	printf("Address e = %d\n", &(((structc_t *)0)->e));
	printf("Address s = %d\n", &(((structc_t *)0)->s)); //16

printf("************************************************\n");
	printf("Address c = %d\n", &(((struct3c_t *)0)->c)); //0
	printf("Address d = %d\n", &(((struct3c_t *)0)->d)); //1
	printf("Address e = %d\n", &(((struct3c_t *)0)->e)); //2

	printf("************************************************\n");
	printf("Address c = %d\n", &(((structa_t *)0)->c)); //0
	printf("Address d = %d\n", &(((structa_t *)0)->s)); //2
	printf("Address e = %d\n", &(((structa_t *)0)->d)); //4
	printf("Address s = %d\n", &(((structa_t *)0)->e)); //6



	printf("sizeof y is %d double = %d\n",sizeof(y), sizeof(double));
	printf("sizeof z is %d\n",sizeof(z));
}



struct desig_struct
{
	int a;
	int b;
	int c;
	};

int test_structure_designated_init_q11()
{
	struct desig_struct x = {.c =67, .b=99, .a=100};
	printf("%d %d %d \n", x.a, x.b, x.c);
}


