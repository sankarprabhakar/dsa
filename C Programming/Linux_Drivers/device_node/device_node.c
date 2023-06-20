/*
 * device_node.c
 *
 *  Created on: Aug 21, 2018
 *      Author: prabhaka
 */


/*
 * Manual creation : mknod -m <permissions> <name> <device type> <major> <minor>
 * */
/*
 * Dynamic creation is using create_class and
 *
 * struct class * class_create (struct module *owner, const char *name);
 *
 *
 *
 * struct device *device_create (struct *class, struct device *parent,
 *
 *                           dev_t dev, const char *fmt, ...);
 *
 *
 * void device_destroy (struct class * class, dev_t devt);
 * */



#include <linux/kernel.h>
#include <linux/init.h>
/*Moudle specific macro's - eg author license, description, version*/
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>


#include <linux/device.h>
#include <linux/kdev_t.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sankar P S");
MODULE_DESCRIPTION("This is a test driver");
MODULE_VERSION("2:1.0");

int varParam = 0;
int varArray[4];
int varCb = 0;
module_param(varParam,int,S_IRUSR|S_IWUSR);
module_param_array(varArray,int,NULL,S_IRUSR|S_IWUSR);



/* kernel_param_ops {
        int (*set)(const char *val, const struct kernel_param *kp);
        int (*get)(char *buffer, const struct kernel_param *kp);
        void (*free)(void *arg);
};*/

int my_setter(const char *val, const struct kernel_param *kp)
{
	int res = param_set_int(val, kp);
	if(res ==  0)
	{
		printk(KERN_INFO "param set int success\n");
		return 0;
	}
	else
	{
		return res;
	}

}

#if 0
int my_getter(char *buffer, const struct kernel_param *kp)
{

	int res = parm_get_int(val, kp);
	if(res ==  0)
	{
		printk(KERN_INFO "param get int success\n");
		return 0;
	}
	else
	{
		return res;
	}
}
#endif

const struct kernel_param_ops my_param_ops =
{
        .set = &my_setter, // Use our setter ...
        .get = &param_get_int, // .. and standard getter
};

module_param_cb(varCb, &my_param_ops,&varCb,S_IRUSR|S_IWUSR);

/*
 * 1. how to pass a single parameter.
 * sudo echo 1 > /sys/modules/<module name>/parameters/<variable name>
 * 2.how to pass a array
 * sudo echo 1,2,3,4 > /sys/modules/<module name>/parameters/<array variable name>
 * 3.
 *
 *
 *
 * */

/*getter and setter declaration*/

dev_t devno = 0;//MKDEV(235, 0);
struct class *tc;
struct device *td;
int __init my_init_function(void)
{
	//printk(KERN_INFO "%s:%d is called value of param = %d \n",__FUNCTION__,__LINE__,varParam);
	int ret = alloc_chrdev_region(&devno,1,1,"mydriver");


	/*
	 * int alloc_chrdev_region(dev_t *dev, unsigned int firstminor, unsigned int count, char *name);
	 *
	 *
	 * */
	if(ret < 0)
	{
		printk(KERN_ERR "%s:%d is called value Failed to register the device\n",__FUNCTION__,__LINE__);
	}
	else
	{
		printk(KERN_ERR "%s:%d is called value New Major number = %d\n",__FUNCTION__,__LINE__, MAJOR(devno));
	}

	tc  =  class_create(THIS_MODULE,"mytestdriver_class");
	if(tc == NULL)
	{
		printk(KERN_ERR "%s:%d is called class_create failed with NULL returned\n",__FUNCTION__,__LINE__);
		return 1;
	}
	td = device_create(tc,NULL,devno,NULL,"mydriver");
	if(td == NULL)
		{
			printk(KERN_ERR "%s:%d is called device_create failed with NULL returned\n",__FUNCTION__,__LINE__);
			return 1;
		}



	return 0;
}

void __exit my_terminate_function(void)
{
  printk(KERN_INFO "%s:%d is called value of param = %d \n",__FUNCTION__,__LINE__,varParam);
/*prototype:
 * void unregister_chrdev_region(dev_t first, unsigned int count);
 *
 * */
     unregister_chrdev_region(devno,1);


     device_destroy(tc,devno);
     class_destroy(tc);
	int i = 0;
	for(i=0;i<4;i++)
		printk(KERN_INFO "Val i = %d varArray[i] = %d \n", i, varArray[i]);
//	return 0;
}

module_init(my_init_function);
module_exit(my_terminate_function);

