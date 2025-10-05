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
