#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/time.h>
#include <linux/input.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/mman.h>
#include <signal.h>
#define BUF_SIZE 100
