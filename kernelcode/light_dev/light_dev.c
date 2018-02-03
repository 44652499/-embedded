#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/input.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>
#include <linux/device.h>

#define  DEVICE_NAME  "light"

static int major;
static struct class * light_class;
static struct device * light_class_dev;

volatile unsigned long *GPH3CON = NULL;
volatile unsigned long *GPH3DAT = NULL;

static int light_open(struct inode* node, struct file* file)
{
     printk("hello_open\n");
     *GPH3CON &= ~(0xf | 0xf<<(1*4) | 0xf<<(2*4) | 0xf<<(3*4));//清零(输入模式)
     *GPH3CON |=  (0x1 | 0x1<<(1*4) | 0x1<<(2*4) | 0x1<<(3*4));//输出模式

     *GPH3DAT &= ~(0x1 | 0x1<<1 | 0x1<<2 | 0x1<<3);  //把3 4 5 6设置为0

     return 0;
}

static int light_write(struct file *file, const char __user *buf, size_t count, loff_t * loff)
{
    unsigned int val;
     printk("hello_write\n");
     copy_from_user(&val,buf,4);//从用户空间拷贝到内核空间
	 // (*GPH3DAT) &= ~(0x1<<3 | 0x1<<4);
     printk("val:%d",val);	
	 (*GPH3DAT) &= ~(0x1 | 0x1<<1 | 0x1<<2 | 0x1<<3);
     switch(val)
     {	
         case 0:
             (*GPH3DAT) &= ~(0x1 | 0x1<<1 | 0x1<<2 | 0x1<<3);
             break;
		 case 1:  
			 (*GPH3DAT) |= (0x1);   //一档灯开
			 break;
         case 2:
             (*GPH3DAT) |= (0x1 | 0x1<<1);   //二档灯开
			 break;
         case 3:
             (*GPH3DAT) |= (0x1 | 0x1<<1 | 0x1<<2);    //三档灯开
             break;
         case 4:
             (*GPH3DAT) |= (0x1 || 0x1<<1 || 0x1<<2 || 0x1<<3);   //四档灯开
             break;
         default:		 
			 break;
     }
     return 0;
}

static ssize_t light_read(struct file *file,char __user *buf, size_t size, loff_t * loff)
{
	 unsigned char keyval;

	 if (size != sizeof(keyval))
	 {
		 return -EINVAL;
	 }
	 keyval = *GPH3DAT;
     //由内核拷贝到用户
	 copy_to_user(buf,&keyval,sizeof(keyval));

     return 0;
}

static struct file_operations light_ops={
     .owner   = THIS_MODULE,
     .open = light_open,
     .write = light_write,
     .read = light_read,
};

static int __init light_init(void)
{
    printk("light_init!\n");
    major = register_chrdev(0,DEVICE_NAME,&light_ops);

    light_class  = class_create(THIS_MODULE,DEVICE_NAME);
    light_class_dev = device_create(light_class,NULL,MKDEV(major,0),NULL,DEVICE_NAME);
    GPH3CON = (volatile unsigned long*)ioremap(0xE0200C60,32);
    GPH3DAT = (volatile unsigned long*)ioremap(0xE0200C64,32);

    return 0;
}

static void __exit light_exit(void)
{
    printk("curtain_exit!\n");
    device_unregister(light_class_dev);
    class_destroy(light_class);
    iounmap(GPH3CON);
    unregister_chrdev(major,DEVICE_NAME);
    return;
}

module_init(light_init);
module_exit(light_exit);

MODULE_LICENSE("GPL");
