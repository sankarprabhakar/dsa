/*
 * linuxdriver.c
 *
 *  Created on: Aug 16, 2018
 *      Author: prabhaka
 */

//#include <linux/kernel.h>

/*Moudle specific macro's - eg author license, description, version*/
#include <linux/module.h>

//#include <linux/init.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sankar P S");
MODULE_DESCRIPTION("This is a test driver");
MODULE_VERSION("2:1.0");


int __init my_init_function(void)
{
	printk(KERN_INFO "%s:%d is called \n",__FUNCTION__,__LINE__);
	return 0;
}

void __exit my_terminate_function(void)
{
	printk(KERN_INFO "%s:%d is called \n",__FUNCTION__,__LINE__);
//	return 0;
}

module_init(my_init_function);
module_exit(my_terminate_function);
