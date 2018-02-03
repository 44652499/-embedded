#include "define_header.h"
//系统错误信息输出
void   print_sys_error_info(const char* error_title)
{
    perror(error_title);
    exit(-1);
}
//led灯控制
//on 控制亮灭  1 亮  0 灭
//index  控制第几个led灯亮  0-3 4个led
void  led_on_off(int  on,int index)
{
    int led_fd=open("/dev/leds",FILE_RD_OPEN);
    if(led_fd==-1)
    {
        print_sys_error_info("open /dev/leds:");
    }
    ioctl(led_fd, on, index);
}
//按键操作
void  button_pressed()
{
    int button_fd;
    char buttons[8]={'0','0','0','0','0','0','0','0'};
    button_fd=open("/dev/buttons",FILE_RD_OPEN);
    if(button_fd==-1)
    {
        print_sys_error_info("open /dev/buttons:");
    }
    //轮询读取按键
    for(;;)
    {
        char  current_buttons[8];
        int i;
        int read_bytes=read(button_fd,current_buttons,sizeof(current_buttons));
        if(read_bytes!=sizeof(current_buttons))
        {
            print_sys_error_info("read buttons:");
        }
        for(i=0;i<sizeof(buttons)/sizeof(buttons[i]);i++)
        {
            if(buttons[i]!=current_buttons[i])
            {
                buttons[i]=current_buttons[i];
                //判断是否被按下:1 按键 0 松键
                if(buttons[i]==49)
                {
                    //第一个按键被按下
                    if(i+1==1)
                    {
                         led_on_off(1,0);
                    }
                    //第二个按键被按下
                    if(i+1==2)
                    {
                        led_on_off(0,0);
                    }
                }
            }
        }
    }
    close(button_fd);
}


int main(int argc,const char* argv[])
{
    button_pressed();
    return 0;
}