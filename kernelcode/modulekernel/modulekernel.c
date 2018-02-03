#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#define DEBUG
#ifdef  DEBUG
#define PRINTK(fmt,arg...)  printk(KERN_WARNING fmt,##arg)
#else
#define PRINTK(fmt,arg...) printk(KERN_DEBUG fmt,##arg)
#endif

static int __init modulekernel_init(void)
{
	PRINTK("modulekernel_init\n");
	return 0;
} 

static void __exit modulekernel_exit(void)
{
	PRINTK("modulekernel_exit\n");
}

module_init(modulekernel_init);
module_exit(modulekernel_exit);
MODULE_AUTHOR("jon lee");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("modulekernel init");