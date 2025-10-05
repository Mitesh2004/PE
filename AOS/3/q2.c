#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t cpid;
void t(int s){ printf("Child did not finish in 5 sec. Killing child...\n"); kill(cpid,SIGKILL); }

int main(){
    signal(SIGALRM,t);
    if((cpid=fork())==0) execlp("sleep","sleep","10",NULL),exit(1);
    alarm(5);
    int st; waitpid(cpid,&st,0);
    printf(WIFEXITED(st) ? "Child exited normally: %d\n" : "Child killed by signal %d\n",WIFEXITED(st) ? WEXITSTATUS(st) : WTERMSIG(st));
    printf("Parent exiting.\n");
}
