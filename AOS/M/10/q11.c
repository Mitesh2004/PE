#include <stdio.h>
int main(){
    freopen("out.txt","w",stdout);
    printf("22+12345= %d",(22+12345));
    printf("This text will be written to the file!\nHello, file redirection works!\n");
}

