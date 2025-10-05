#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){
    pid_t pid=fork();
    if(pid<0) return perror("fork"),1;

    if(!pid){ // child
        while(1){ printf("Child (PID=%d) running...\n",getpid()); sleep(1); }
    } else {  // parent
        sleep(3);
        printf("Parent: Suspending child %d\n",pid); kill(pid,SIGSTOP);
        sleep(5);
        printf("Parent: Resuming child %d\n",pid); kill(pid,SIGCONT);
        sleep(3);
        printf("Parent: Killing child %d\n",pid); kill(pid,SIGKILL);
        wait(NULL);
        puts("Parent: Child terminated, exiting.");
    }
}
