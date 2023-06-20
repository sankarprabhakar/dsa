/*
 * enumerations.c
 *
 *  Created on: Oct 3, 2016
 *      Author: sankarsa
 */

#if 1
void enum_main()
{
	test_enum_qno1();
	test_enum_qno2();
	test_enum_qno3();
	test_enum_qno4();
}
#endif

/***********************************************************************/
test_enum_qno1()
{
	enum Weekdays {sun,mon,tue,thu,fri,sat};
	enum Weekdays day1 = sun;
	printf("Size of enum mon = %d \n", sizeof(mon)); //Sizeof an integer is alloted for enum variable;
	printf("Day 1 = %d fri = %d\n",day1, fri);

}
/**************************************************************************/
//enum Workdays {mon = 66};
test_enum_qno2()
{
	enum Weekdays {sun,mon,tue,wed,fri,sat};
	//enum Workdays {mon}; // uncomment this line results in compilation error, same identifier for 2 enum variables

	printf("Working day = %d\n", mon);
}
/*****************************************************************************/
/*two enum with same name*/
test_enum_qno3()
{
	 enum State {LIVE=1, FREEZE=0, DEATH=0};
	 printf("Freeze = %d, Death = %d \n", FREEZE,DEATH);
}
/******************************************************************************/

test_enum_qno4()
{
	enum Weekdays {sun=20,mon=1,tue=5,wed,fri=19,sat};//Duplicate values are possible in enums. Here sat will have value of 20.
	printf("Value of sun = %d value of sat = %d wed = %d  \n", sun,sat,wed);

}
/*******************************************************************************/
test_enum_qno5()
{
	enum weekdays {a,b};
	enum weekdays x = a;
//	int a = 89; //This is a compilation error duplicate declaration
	//enum weekdays1 {b,a}; //-- this gives compilation error
}


/*
 * 1. enum has scope rules
 * 2. Auto incremented values
 * */
