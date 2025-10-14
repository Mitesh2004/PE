#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2]; char buf[100];
    pipe(fd);
    if(fork()){ // parent
        close(fd[0]);
        write(fd[1],"Hello from parent!",18);
        close(fd[1]);
    }else{      // child
        close(fd[1]);
        read(fd[0],buf,sizeof(buf));
        printf("Child read: %s\n",buf);
        close(fd[0]);
    }
}

