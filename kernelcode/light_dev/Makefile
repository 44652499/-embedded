KERNEL_DIR=/home/linux-3.0.8
PWD=$(shell pwd)
obj-m=light_dev.o
all:
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules
	@rm -rf *.mod.*
	@rm -rf .*.cmd
	@rm -rf *.o
	@rm -rf modules.*
	@rm -rf Module.*
clean:
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD) clean
