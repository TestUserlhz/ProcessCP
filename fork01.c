#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

 pid_t pid;

 pid=fork();
  if(pid>0)
 {
   //父进程工作区
   printf("is parent process.... \n");

 }
  else if(pid==0)
 {
  
   //子进程工作区 执行代码后不要踏出任务区
   printf("is child process.... \n");
   exit(0);
 }
 else
 {

  perror("FORK CALL FAILED");
  exit(-1);
 }
 printf("shared area \n");
 return 0;
}
