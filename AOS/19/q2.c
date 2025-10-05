// same as slip 7,8

#include <unistd.h>
#include <stdio.h>
int main(){
    int p[2]; pipe(p);
    if(!fork()){dup2(p[1],1);close(p[0]);execlp("ls","ls","-l",0);}
    close(p[1]);
    char c; int n=0;
    while(read(p[0],&c,1)>0){putchar(c);n+=c=='\n';}
    printf("Total lines:%d\n",n);
}

