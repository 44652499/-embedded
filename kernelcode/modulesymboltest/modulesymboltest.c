#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#define DEBUG

#ifdef  DEBUG
#define PRINTK(fmt,arg...)   printk(KERN_WARNING fmt,##arg)
#else
#define PRINTK(fmt,arg...)   printk(KERN_DEBUG fmt,##arg)
#endif

extern int add_test(int a,int b);
extern int sub_test(int a,int b);

static int __init modulesymbol_init(void)
{
    int a,b;
    a=add_test(20,30);
    b=sub_test(40,50);
    PRINTK("\n add_test result is %d",a);
    PRINTK("\n sub_test result is %d",b);
    return 0;
}

static void __exit modulesymbol_exit(void)
{
    PRINTK("modulesymbol exit");
}

module_init(modulesymbol_init);
module_exit(modulesymbol_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("LZL");