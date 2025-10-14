#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, 1);   // Redirect standard output (stdout) to file
    close(fd);     // Close original file descriptor
    printf("Hello! This goes to output2.txt\n");
}

