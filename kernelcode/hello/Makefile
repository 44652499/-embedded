KERN_DIR = /home/linux-3.0.8
all:
	make -C $(KERN_DIR) M=`pwd` modules  
clean:
	make -C $(KENR_DIR) M=`pwd` modules clean
	rm -rf modules.order
obj-m   = hello.o
