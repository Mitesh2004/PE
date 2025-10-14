#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void h(int s){ puts("Parent: Alarm fired (SIGALRM received from child)"); }

int main() {
    if(!fork()) { // child
        sleep(3);
        printf("Child: Sending SIGALRM to parent (PID=%d)\n", getppid());
        kill(getppid(), SIGALRM);
    } else {      // parent
        signal(SIGALRM, h);
        puts("Parent: Waiting for alarm...");
        pause();
        wait(NULL);
        puts("Parent: Child terminated. Exiting.");
    }
}

