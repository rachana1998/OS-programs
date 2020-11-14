#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>


static char* charvar = "rachana";
static int intvar= 10;



module_param(charvar, charp, S_IRUGO);
module_param(intvar, int, S_IRUGO);


static int __init  param_init(void)
{
	printk("am in init function\n");
	printk("the value of charvar is %s\n",charvar);
	printk("the value of intvar is %d\n",intvar);
	return 0;
}
static void __exit param_exit(void)
{
	printk("in exit module\n");
	printk("bye bye\n");
}

module_init(param_init);
module_exit(param_exit);

