#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int c,char**v){
 if(c<2)return printf("Use: %s <bytes>\n",v[0]),0;
 DIR*d=opendir(".");struct dirent*e;struct stat s;long n=atol(v[1]);
 while((e=readdir(d)))if(!stat(e->d_name,&s)&&s.st_size>n)
  printf("%s(%ldB)\n",e->d_name,(long)s.st_size);
 closedir(d);
}

