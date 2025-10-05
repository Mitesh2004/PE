#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {          // child: ls -l
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls", "ls", "-l", NULL);
    } else {                    // parent: print & count
        close(fd[1]);
        char c;
        int count = 0;
        while (read(fd[0], &c, 1) > 0) {
            putchar(c);
            if (c == '\n') count++;
        }
        printf("Total lines: %d\n", count);
    }
    return 0;
}
