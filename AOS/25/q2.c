#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd=open("output2.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
//    if(fd<0) return perror("open"),1;
    if(dup2(fd,1)<0) return perror("dup2"),1;
    close(fd);
    printf("Hello! This goes to output1.txt\n");
}

