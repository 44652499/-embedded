KERN_DIR = /home/linux-3.0.8
PWD=$(shell pwd)
obj-m= hello.o
all:
	make -C $(KERN_DIR) SUBDIRS=$(PWD) modules
	@rm -rf *.mod.*
	@rm -rf .*.cmd
	@rm -rf *.o
	@rm -rf modules.*
	@rm -rf Module.*
clean:
	rm -rf *.ko

