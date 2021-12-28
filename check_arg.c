#include "pcpy.h"


int check_arg(const char * SFile,int arg_num,int pronum)
{

   //文件是否存在
   if(access(SFile,F_OK)!=0)
    {
         perror("Check_Arg ERROR");
         exit(-1);
    }
   //参数数量是否满足
   if(arg_num<3)
    {
        printf("参数数量异常！");
        exit(-1);

    }
    if(pronum<=0 || pronum>=100)
    {
        printf("Check Error:  进程数量异常");
        exit(-1);
    }
  return 0;
}

