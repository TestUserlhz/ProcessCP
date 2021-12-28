#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(void)
{

 pid_t pid;
 pid_t zpid;
 for(int i=0;i<10;i++)
 {
    pid=fork();
     if(pid==0)
        break;
 }
  if(pid>0)
 {
   //父进程工作区
   printf(" parent process pid [%d] \n",getpid());
  
     while((zpid=wait(NULL))!=-1) //多个子进程，循环回收处理 !=-1;
    {
     printf("parent wait successfully    zombie pid [%d]\n",zpid);
    }
    
 }
  else if(pid==0)
 {
  
   //子进程工作区 执行代码后不要踏出任务区
   printf("child process pid [%d]\n",getpid());
   exit(0);  //提前终止
 }
 else
 {

  perror("FORK CALL FAILED");
  exit(-1);
 }
 return 0;
}
