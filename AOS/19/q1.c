#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int c,char *v[]){struct stat s;
//    if(c<2) return printf("Use: %s <file>\n",v[0]),1;
    for(int i=1;i<c;i++){char cmd[100];
        snprintf(cmd,100,"file -b %s",v[i]);
        system(cmd);
        if(!stat(v[i],&s)) printf("inode:%lu\n",s.st_ino);
    }
}
//./a.out q1.c


