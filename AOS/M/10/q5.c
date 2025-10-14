#include <stdio.h>

int main(int c, char *v[]){
    FILE *f = fopen(v[1],"r");
    if(f) printf("File exists\n"), fclose(f);
    else  printf("File not found\n");
}

