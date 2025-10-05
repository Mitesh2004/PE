#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd[2]; char buf[100]; pipe(fd);
    if(fork()==0){          // child
        close(fd[0]);
        char *msg[]={"Hello World","Hello SPPU","Linux is Funny"};
        for(int i=0;i<3;i++){
            write(fd[1], msg[i], 100); // write fixed 100 bytes
        }
        close(fd[1]);
    }else{                  // parent
        close(fd[1]);
        for(int i=0;i<3;i++){
            read(fd[0], buf, 100);
            printf("Parent received: %s\n", buf);
        }
        close(fd[0]);
    }
}
