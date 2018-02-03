#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <sys/mman.h>
#include <sys/file.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <pthread.h>
#include <semaphore.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <linux/if_ether.h>
#include <linux/if.h>
#include <linux/sockios.h>
//#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <netinet/ip_icmp.h>
#define  MSG_EXCEPT      020000 
#define  PORT 12345
#define  PRONUM 10
#define  BUFSIZE 1024
#define  NUM  10







