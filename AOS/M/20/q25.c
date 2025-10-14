#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int c=0;
void h(int s){
    if(++c==1) printf("\nCaught Ctrl-C! Press again to exit.\n");
    else { printf("\nExiting program.\n"); exit(0); }
}

int main(){
    signal(SIGINT,h);
    puts("Press Ctrl-C...");
    while(1);
}

