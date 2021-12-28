#include "pcpy.h"


int procreate(const char * SFile,const char * DFile,int pronum,int blocksize)
{
  int flag;
  int pos;
  pid_t pid;
  char cblock[10];
  char cpos[10];
  bzero(cblock,sizeof(cblock));
  bzero(cpos,sizeof(cpos));
     for(flag=0;flag<10;flag++)
     {
       pid=fork();
       if(pid==0)
        break;
     }
    if(pid>0)
    {
      printf("Parent pro pid[%d]  非阻塞回收....\n",getpid());
      pid_t zpid;
      while((zpid=waitpid(-1,NULL,WNOHANG))!=-1)
      {
         if(zpid>0)
           printf("Parent wait success:  zombie pid[%d]\n",zpid);

      }

    }
    else if(pid==0)
    {
      //计算偏移量
         pos=flag*blocksize;
         sprintf(cblock,"%d",blocksize);  //整形转字符串
         sprintf(cpos,"%d",pos);
       //重载拷贝功能
       execl("/home/colin/1123晚班/PROCESS/COPY","COPY",SFile,DFile,cblock,cpos,NULL);

    }
    else{
       perror("FORK CALL Failed");
       exit(-1);
    }

}


