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
     *GPH3CON &= ~(0xf | 0xf<<(1*4) | 0xf<<(2*4) | 0xf<<(3*4));//����(����ģʽ)
     *GPH3CON |=  (0x1 | 0x1<<(1*4) | 0x1<<(2*4) | 0x1<<(3*4));//���ģʽ

     *GPH3DAT &= ~(0x1 | 0x1<<1 | 0x1<<2 | 0x1<<3);  //��3 4 5 6����Ϊ0

     return 0;
}

static int light_write(struct file *file, const char __user *buf, size_t count, loff_t * loff)
{
    unsigned int val;
     printk("hello_write\n");
     copy_from_user(&val,buf,4);//���û��ռ俽�����ں˿ռ�
	 // (*GPH3DAT) &= ~(0x1<<3 | 0x1<<4);
     printk("val:%d",val);	
	 (*GPH3DAT) &= ~(0x1 | 0x1<<1 | 0x1<<2 | 0x1<<3);
     switch(val)
     {	
         case 0:
             (*GPH3DAT) &= ~(0x1 | 0x1<<1 | 0x1<<2 | 0x1<<3);
             break;
		 case 1:  
			 (*GPH3DAT) |= (0x1);   //һ���ƿ�
			 break;
         case 2:
             (*GPH3DAT) |= (0x1 | 0x1<<1);   //�����ƿ�
			 break;
         case 3:
             (*GPH3DAT) |= (0x1 | 0x1<<1 | 0x1<<2);    //�����ƿ�
             break;
         case 4:
             (*GPH3DAT) |= (0x1 || 0x1<<1 || 0x1<<2 || 0x1<<3);   //�ĵ��ƿ�
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
     //���ں˿������û�
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
