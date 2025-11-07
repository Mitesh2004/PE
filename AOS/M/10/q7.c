#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *f;
    DIR *d = opendir(".");
    int c = 0;
    while ((f = readdir(d)))
        if (*f->d_name != '.')
            printf("%s\n", f->d_name), c++;
    printf("Total files: %d\n", c);
    closedir(d);
}

