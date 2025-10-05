#include <stdio.h>

int main(int c, char *v[]) {
//    if(c != 2) return printf("Usage: %s <file>\n", v[0]),1;

    FILE *f = fopen(v[1], "r");
    if(f) printf("File exists\n"), fclose(f);
    else   printf("File not found\n");
}

