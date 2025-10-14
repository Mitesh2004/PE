#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int c, char *v[]) {
    DIR *d = opendir(".");        // Open current directory
    struct dirent *f;

    while ((f = readdir(d))) {    // Read each file in directory
        if (strncmp(f->d_name, v[1], strlen(v[1])) == 0)
            puts(f->d_name);      // Print file if it starts with prefix
    }

    closedir(d);                  // Close directory
}

