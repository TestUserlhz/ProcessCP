#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(void)
{

 pid_t pid;
 pid_t zpid;
 pid=fork();
  if(pid>0)
 {
   //父进程工作区
   printf(" parent process pid  %d\n",getpid());
   //多子进程模型中 采用循环回收
     while((zpid=waitpid(-1,NULL,WNOHANG))!=-1)
    {
          if(zpid>0)
         {  
           printf("parent wait successfully, zobime pid %d\n",zpid); 
         }
         else    //子进程还在执行，不可回收
          { 
             printf("parent exec....\n");
             sleep(1);
          }
    }

 }
  else if(pid==0)
 {
  
   //子进程工作区 
   printf("child process pid [%d]\n",getpid());
   sleep(8);
   exit(0);  //子进程中止
 }
 else
 {

   perror("FORK CALL FAILED");
   exit(-1);
 }
 return 0;
}
