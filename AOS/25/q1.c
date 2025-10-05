#include <stdio.h>

int main() {
    // Redirect stdout to a file
    freopen("output.txt", "w", stdout);

    // Anything printed now goes to output.txt instead of console
    printf("This text will be written to the file!\n");
    printf("Hello, file redirection works!\n");

    return 0;
}

