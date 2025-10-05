#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void h(int s){ puts("Parent: Alarm fired (SIGALRM received from child)"); }

int main(){
    pid_t pid=fork();
//    if(pid<0) return perror("fork"),1;

    if(!pid){ // child
        sleep(3);
        printf("Child: Sending SIGALRM to parent (PID=%d)\n",getppid());
        kill(getppid(),SIGALRM);
        exit(0);
    } else {  // parent
        signal(SIGALRM,h);
        puts("Parent: Waiting for alarm...");
        pause();        // wait for SIGALRM
        wait(NULL);     // wait for child
        puts("Parent: Child terminated. Exiting.");
    }
}
