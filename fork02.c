#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

 pid_t pid;
 int flag;
 for(flag=0;flag<5;flag++)
 { 

    pid=fork();
    if(pid==0)
     break;
 }
  if(pid>0)
 {
   //父进程工作区
   printf("is parent process.... \n");
   while(1)
    sleep(1);
 }
  else if(pid==0)
 {
  
   //子进程工作区 执行代码后不要踏出任务区
   printf("is child process....  flag[%d] \n",flag);
    while(1)
     sleep(1);
 }
 else
 {

  perror("FORK CALL FAILED");
  exit(-1);
 }
 printf("shared area \n");
 return 0;
}
