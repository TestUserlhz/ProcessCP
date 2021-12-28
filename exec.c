#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(void)
{

   pid_t pid;
   pid=fork();
   if(pid>0)
  {
     //父进程工作区
     printf(" parent process pid  %d\n",getpid());
     while(1)        
      sleep(1);
 }
  else if(pid==0)
 {
  
   //子进程工作区 
   printf("child pid [%d] exec jobs\n",getpid());  //子进程自身内容a
   execl("/usr/bin/firefox","firefox","www.bilibili.com",NULL); //功能重载
   printf("exec firefox success! \n");//自身内容b
 }
 else
 {

   perror("FORK  FAILED");
   exit(0);
 }
 return 0;
}
