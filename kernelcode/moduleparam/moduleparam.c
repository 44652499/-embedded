#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#define DEBUG

#ifdef DEBUG
#define PRINTK(fmt,arg...)  printk(KERN_WARNING fmt,##arg)
#else
#define PRINTK(fmt,arg...)  printk(KERN_DEBUG fmt,##arg)
#endif

static char * string_test="test param default value";
static int  num_test=100;

static int __init moduleparam_init(void)
{
   PRINTK("\tthe string_test is :%s\n",string_test);
   PRINTK("\tthen num_test is  :%d\n",num_test);
   return 0;
}

static void __exit moduleparam_exit(void)
{   
	PRINTK("input param exit\n");
}

module_init(moduleparam_init);
module_exit(moduleparam_exit);
module_param(string_test,charp,S_IRUGO);
module_param(num_test,int,S_IRUGO);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("LZL");