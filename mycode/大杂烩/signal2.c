#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handler(int sig)
{
   printf("Deal SIGINT");
}

int main(int argc, char const *argv[])
 {
    sigset_t newmask;
    sigset_t oldmask;
    sigset_t pendmask;
   struct sigaction act;
   act.sa_handler = handler;
   sigemptyset(&act.sa_mask);
   act.sa_flags = 0;
   sigaction(SIGINT, &act, 0);  //�źŲ�׽��������׽Ctrl+C
   //pause();

   sigemptyset(&newmask);//��ʼ���ź�����
   sigaddset(&newmask, SIGINT);//��SIGINT��ӵ��ź�������

  sigprocmask(SIG_BLOCK, &newmask,&oldmask);//��newmask�е�SIGINT�������������浱ǰ�ź������ֵ�Oldmask

 sleep(5);//����5���ӣ�˵��:��5s�����ڼ䣬�κ�SIGINT�źŶ��ᱻ�����������5s���յ��κμ��̵�Ctrl+C�źţ����ʱ�����Щ��Ϣ�����ں˵Ķ����У��ȴ�5s�����󣬿���Ҫ������źš�
 sigpending(&pendmask);//����ź�������δ����,
 if (sigismember(&pendmask, SIGINT))//SIGINT������δ���ġ���ν����δ������ָSIGINT��������û�б�����
 {
 printf("/nSIGINT pending/n");
 }
 sigprocmask(SIG_SETMASK, &oldmask, NULL);//�ָ������ε��ź�SIGINT

  //�˴���ʼ�����źţ������źŴ�����
 printf("SIGINT unblocked/n");
    return 0;
}

//sigprocmask(SIG_BLOCK, &newmask, NULL); //����
//sigprocmask(SIG_UNBLOCK, &newmask, NULL);//ȡ������
