#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(void)
{

 pid_t pid;
 pid_t zpid;
 int status;  //通过status对子进程 退出原因进行校验;
 

 pid=fork();
  if(pid>0)
 {
   //父进程工作区
   printf(" parent process pid  %d\n",getpid());
   zpid=wait(&status);//传出子进程退出原因
     if(WIFEXITED(status))  //正常退出返回1 异常退出返回0;
     {
        printf("回收成功， 僵尸pid %d ,进程正常退出 exit 或 return 退出码 %d\n",zpid,WEXITSTATUS(status));

     }
    
    if(WIFSIGNALED(status))  //异常退出校验
    {
       printf("回收成功， 僵尸pid %d ,进程异常退出，信号编号: %d\n ",zpid,WTERMSIG(status));

    } 
 }
  else if(pid==0)
 {
  
   //子进程工作区 
   printf("child process pid [%d]\n",getpid());
   //exit(8); //正常退出
   //进程在执行中，被信号杀死（Linux 消息机制，杀死），异常退出;
   while(1);
 }
 else
 {

   perror("FORK CALL FAILED");
   exit(-1);
 }
 return 0;
}
