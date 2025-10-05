#include<stdio.h>
#include <sys/stat.h>
int main(int c,char*v[]){
    struct stat s;
   // if(c<2)return 0;
    stat(v[1],&s);
    puts(S_ISREG(s.st_mode)?"Regular":
         S_ISDIR(s.st_mode)?"Dir":
         S_ISCHR(s.st_mode)?"Char Dev":
         S_ISBLK(s.st_mode)?"Block Dev":
         S_ISFIFO(s.st_mode)?"FIFO":
         S_ISLNK(s.st_mode)?"Link":
         S_ISSOCK(s.st_mode)?"Socket":"Unknown");
}


/*
#include<stdio.h>
#include <sys/stat.h>

int main(int c,char *v[]){
    if(c!=2) return printf("Usage: %s <file>\n",v[0]),1;
    struct stat s; if(stat(v[1],&s)<0) return perror("stat"),1;
    printf("File: %s\nType: ",v[1]);
    if(S_ISREG(s.st_mode)) puts("Regular file");
    else if(S_ISDIR(s.st_mode)) puts("Directory");
    else if(S_ISCHR(s.st_mode)) puts("Character device");
    else if(S_ISBLK(s.st_mode)) puts("Block device");
    else if(S_ISFIFO(s.st_mode)) puts("FIFO / Pipe");
    else if(S_ISLNK(s.st_mode)) puts("Symbolic link");
    else if(S_ISSOCK(s.st_mode)) puts("Socket");
    else puts("Unknown");
}*/

