#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count=0;

void handle(int sig){
    if(++count==1) printf("\nCaught Ctrl-C! Press again to exit.\n");
    else { printf("\nExiting program.\n"); exit(0); }
}

int main(){
    signal(SIGINT, handle);
    printf("Press Ctrl-C...\n");
    while(1);
}
/*
 m@Debian:~/Desktop/OS/MCS_Sem-1/golfed_code$ vim q25.c
m@Debian:~/Desktop/OS/MCS_Sem-1/golfed_code$ gcc q25.c
m@Debian:~/Desktop/OS/MCS_Sem-1/golfed_code$ ./a.out
Press Ctrl-C...
^C
Caught Ctrl-C! Press again to exit.
^C
Exiting program.
*/

/*
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(){
    static int count = 0;

    void handler(int sig){       // signal handler must be a real function
        count++;
        if(count==1) printf("\nCaught Ctrl-C! Press again to exit.\n");
        else { printf("\nExiting program.\n"); exit(0); }
    }

    signal(SIGINT, handler);

    printf("Press Ctrl-C...\n");
    while(1); // wait for signals
}
*/
/*
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void handle_sigint(int sig) {
    count++;
    if (count == 1) {
        printf("\nCaught Ctrl-C! Press again to exit.\n");
    } else {
        printf("\nExiting program.\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, handle_sigint); // Register handler

    printf("Press Ctrl-C...\n");

    while (1) {
        // Infinite loop, waiting for signals
    }

    return 0;
}
*/
