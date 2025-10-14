#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t c;
void h(int s){ puts("Timeout! Killing child..."); kill(c,SIGKILL); }

int main(){
    signal(SIGALRM,h);
    if(!(c=fork())) execlp("sleep","sleep","10",0);
    alarm(5);
    int st; wait(&st);
    printf(WIFEXITED(st)?"Child exited normally\n":"Child killed by signal\n");
}


/*
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t cpid;
void t(int s){ puts("Child did not finish in 5 sec. Killing child..."); kill(cpid,SIGKILL); }

int main(){
    signal(SIGALRM,t);
    if(!(cpid=fork())) execlp("sleep","sleep","10",NULL);
    alarm(5);
    int st; waitpid(cpid,&st,0);
    printf(WIFEXITED(st) ? "Child exited normally: %d\n" : "Child killed by signal %d\n", WIFEXITED(st) ? WEXITSTATUS(st) : WTERMSIG(st));
    puts("Parent exiting.");
}
*/

/*
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t cpid;
void t(int s){ puts("Child did not finish in 5 sec. Killing child..."); kill(cpid,SIGKILL); }

int main(){
    signal(SIGALRM,t);
    if(!(cpid=fork())) execlp("sleep","sleep","10",NULL);
    alarm(5);
    int st; waitpid(cpid,&st,0);
    printf(WIFEXITED(st) ? "Child exited normally: %d\n"
                         : "Child killed by signal %d\n",
           WIFEXITED(st) ? WEXITSTATUS(st) : WTERMSIG(st));
    puts("Parent exiting.");
}
*/
