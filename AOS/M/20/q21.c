#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; 
    pipe(fd);
    if(!fork()) {          // child
        close(fd[0]);
        char *msg[] = {"Hello World","Hello SPPU","Linux is Funny"};
        for(int i=0;i<3;i++){ write(fd[1], msg[i], 100);}
        close(fd[1]);
    } else {                // parent
        close(fd[1]);
        char buf[100];
        for(int i=0;i<3;i++){ read(fd[0], buf, 100); printf("%s\n", buf); }
        close(fd[0]);
    }
}


