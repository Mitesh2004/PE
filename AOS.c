(1)

#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    for (int i = 1; i < c; i++) {
        stat(v[i], &s);
        printf("File: %s\nInode: %lu\n", v[i], s.st_ino);
        puts(S_ISREG(s.st_mode) ? "Regular file" :S_ISDIR(s.st_mode) ? "Directory" :S_ISCHR(s.st_mode) ? "Character device" :S_ISBLK(s.st_mode) ? "Block device" :S_ISFIFO(s.st_mode) ? "FIFO/Pipe" :S_ISLNK(s.st_mode) ? "Symbolic link" :S_ISSOCK(s.st_mode) ? "Socket" : "Unknown");
        puts("");
    }
}

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void h(int s){ puts("Parent: Alarm fired (SIGALRM received from child)"); }

int main() {
    if(!fork()) { // child
        sleep(3);
        printf("Child: Sending SIGALRM to parent (PID=%d)\n", getppid());
        kill(getppid(), SIGALRM);
    } else {      // parent
        signal(SIGALRM, h);
        puts("Parent: Waiting for alarm...");
        pause();
        wait(NULL);
        puts("Parent: Child terminated. Exiting.");
    }
}






(2)

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int c,char *v[]){
    struct stat s; stat(v[1],&s);
    printf("File: %s\nInode:%lu Links:%lu Size:%ld\nPerms:", v[1],s.st_ino,s.st_nlink,s.st_size);

    for(int i=8;i>=0;i--) putchar((s.st_mode&(1<<i))?"rwxrwxrwx"[8-i]:'-');
   
    printf("\nAccess:%sModify:%sChange:%s", ctime(&s.st_atime),ctime(&s.st_mtime),ctime(&s.st_ctime));

}

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int c=0;
void h(int s){
    if(++c==1) printf("\nCaught Ctrl-C! Press again to exit.\n");
    else { printf("\nExiting program.\n"); exit(0); }
}

int main(){
    signal(SIGINT,h);
    puts("Press Ctrl-C...");
    while(1);
}











(3)

#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    for (int i = 1; i < c; i++) {
        stat(v[i], &s);
        printf("File: %s\nInode: %lu\n", v[i], s.st_ino);
        puts(S_ISREG(s.st_mode) ? "Regular file" :
             S_ISDIR(s.st_mode) ? "Directory" :
             S_ISCHR(s.st_mode) ? "Character device" :
             S_ISBLK(s.st_mode) ? "Block device" :
             S_ISFIFO(s.st_mode) ? "FIFO/Pipe" :
             S_ISLNK(s.st_mode) ? "Symbolic link" :
             S_ISSOCK(s.st_mode) ? "Socket" : "Unknown");
        puts("");
    }
}

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t c;
void h(int s){ puts("Timeout! Killing child..."); kill(c,SIGKILL); }

int main(){
    signal(SIGALRM,h);
    if(!(c=fork())) execlp("sleep","sleep","10",0);
    alarm(5);
    int st; wait(&st);
    printf(WIFEXITED(st)?"Child exited normally\n":"Child killed by signal\n");
}












(5)

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


#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; 
    pipe(fd);
    if(!fork()) {          // child
        close(fd[0]);
        char *msg[] = {"Hello World","Hello SPPU","Linux is Funny"};
        for(int i=0;i<3;i++){ write(fd[1], msg[i], 100);}
        close(fd[1]);
    } else {                // parent
        close(fd[1]);
        char buf[100];
        for(int i=0;i<3;i++){ read(fd[0], buf, 100); printf("%s\n", buf); }
        close(fd[0]);
    }
}

















(7)

#include <stdio.h>
int main(){
    freopen("out.txt","w",stdout);
    printf("22+12345= %d",(22+12345));
    printf("This text will be written to the file!\nHello, file redirection works!\n");
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2]; pipe(fd);
    if (!fork()) { dup2(fd[1], 1); close(fd[0]); execlp("ls", "ls", "-l", NULL); }
    close(fd[1]);
    char c; int n = 0;
    while (read(fd[0], &c, 1) > 0) { putchar(c); if (c == '\n') n++; }
    printf("Total lines: %d\n", n);
}


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2];    // pipe for ls -l output
    int fd2[2];    // pipe for wc -l input

    pipe(fd1);
    pipe(fd2);

    if (!fork()) {  
        // Child 1 → run ls -l
        dup2(fd1[1], 1);   // send ls output to fd1
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    if (!fork()) {  
        // Child 2 → run wc -l
        dup2(fd2[0], 0);   // wc reads from fd2
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("wc", "wc", "-l", NULL);
    }

    // Parent: read from ls (fd1), print output, and pass it to wc (fd2)
    close(fd1[1]);
    close(fd2[0]);

    char c;
    while (read(fd1[0], &c, 1) > 0) {
        putchar(c);        // show ls output
        write(fd2[1], &c, 1); // send to wc -l
    }

    close(fd1[0]);
    close(fd2[1]);

    wait(NULL);
    wait(NULL);
}






























(8)

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, 1);   // Redirect standard output (stdout) to file
    close(fd);     // Close original file descriptor
    printf("Hello! This goes to output2.txt\n");
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2]; pipe(fd);
    if (!fork()) { dup2(fd[1], 1); close(fd[0]); execlp("ls", "ls", "-l", NULL); }
    close(fd[1]);
    char c; int n = 0;
    while (read(fd[0], &c, 1) > 0) { putchar(c); if (c == '\n') n++; }
    printf("Total lines: %d\n", n);
}


















(9)

#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2]; char buf[100];
    pipe(fd);
    if(fork()){ // parent
        close(fd[0]);
        write(fd[1],"Hello from parent!",18);
        close(fd[1]);
    }else{      // child
        close(fd[1]);
        read(fd[0],buf,sizeof(buf));
        printf("Child read: %s\n",buf);
        close(fd[0]);
    }
}


#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    for (int i = 1; i < c; i++) {
        stat(v[i], &s);
        printf("File: %s\nInode: %lu\n", v[i], s.st_ino);
        puts(S_ISREG(s.st_mode) ? "Regular file" :
             S_ISDIR(s.st_mode) ? "Directory" :
             S_ISCHR(s.st_mode) ? "Character device" :
             S_ISBLK(s.st_mode) ? "Block device" :
             S_ISFIFO(s.st_mode) ? "FIFO/Pipe" :
             S_ISLNK(s.st_mode) ? "Symbolic link" :
             S_ISSOCK(s.st_mode) ? "Socket" : "Unknown");
    }
}














(11)

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit r;
    getrlimit(RLIMIT_NOFILE, &r);
    printf("Open files: %lu/%lu\n", r.rlim_cur, r.rlim_max);
    getrlimit(RLIMIT_AS, &r);
    printf("Memory: %lu/%lu\n", r.rlim_cur, r.rlim_max);
    r.rlim_cur = 1024;
    setrlimit(RLIMIT_NOFILE, &r);
    getrlimit(RLIMIT_NOFILE, &r);
    printf("Updated open files: %lu/%lu\n", r.rlim_cur, r.rlim_max);
}


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, 1);   // Redirect standard output (stdout) to file
    close(fd);     // Close original file descriptor
    printf("Hello! This goes to output2.txt\n");
}















(13)

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){ pid_t pid=fork();
    if(!pid){
        while(1){ printf("Child (PID=%d) running...\n",getpid()); sleep(1); }
    } else {
        sleep(3); printf("Parent: Suspending child %d\n",pid); kill(pid,SIGSTOP);
        sleep(5); printf("Parent: Resuming child %d\n",pid); kill(pid,SIGCONT);
        sleep(3); printf("Parent: Killing child %d\n",pid); kill(pid,SIGKILL);
        wait(NULL); puts("Parent: Child terminated, exiting.");
    }
}

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




















(15)

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int c,char**v){
 if(c<2)return printf("Use: %s <bytes>\n",v[0]),0;
 DIR*d=opendir(".");struct dirent*e;struct stat s;long n=atol(v[1]);
 while((e=readdir(d)))if(!stat(e->d_name,&s)&&s.st_size>n)
  printf("%s(%ldB)\n",e->d_name,(long)s.st_size);
 closedir(d);
}

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t c;
void h(int s){ puts("Timeout! Killing child..."); kill(c,SIGKILL); }

int main(){
    signal(SIGALRM,h);
    if(!(c=fork())) execlp("sleep","sleep","10",0);
    alarm(5);
    int st; wait(&st);
    printf(WIFEXITED(st)?"Child exited normally\n":"Child killed by signal\n");
}























(18)

#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2]; char buf[100];
    pipe(fd);
    if(fork()){ // parent
        close(fd[0]);
        write(fd[1],"Hello from parent!",18);
        close(fd[1]);
    }else{      // child
        close(fd[1]);
        read(fd[0],buf,sizeof(buf));
        printf("Child read: %s\n",buf);
        close(fd[0]);
    }
}

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; 
    pipe(fd);
    if(!fork()) {          // child
        close(fd[0]);
        char *msg[] = {"Hello World","Hello SPPU","Linux is Funny"};
        for(int i=0;i<3;i++){ write(fd[1], msg[i], 100);}
        close(fd[1]);
    } else {                // parent
        close(fd[1]);
        char buf[100];
        for(int i=0;i<3;i++){ read(fd[0], buf, 100); printf("%s\n", buf); }
        close(fd[0]);
    }
}




















(19)

#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    for (int i = 1; i < c; i++) {
        stat(v[i], &s);
        printf("File: %s\nInode: %lu\n", v[i], s.st_ino);
        puts(S_ISREG(s.st_mode) ? "Regular file" :
             S_ISDIR(s.st_mode) ? "Directory" :
             S_ISCHR(s.st_mode) ? "Character device" :
             S_ISBLK(s.st_mode) ? "Block device" :
             S_ISFIFO(s.st_mode) ? "FIFO/Pipe" :
             S_ISLNK(s.st_mode) ? "Symbolic link" :
             S_ISSOCK(s.st_mode) ? "Socket" : "Unknown");
        puts("");
    }
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2]; pipe(fd);
    if (!fork()) { dup2(fd[1], 1); close(fd[0]); execlp("ls", "ls", "-l", NULL); }
    close(fd[1]);
    char c; int n = 0;
    while (read(fd[0], &c, 1) > 0) { putchar(c); if (c == '\n') n++; }
    printf("Total lines: %d\n", n);
}























(20)

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){ pid_t pid=fork();
    if(!pid){
        while(1){ printf("Child (PID=%d) running...\n",getpid()); sleep(1); }
    } else {
        sleep(3); printf("Parent: Suspending child %d\n",pid); kill(pid,SIGSTOP);
        sleep(5); printf("Parent: Resuming child %d\n",pid); kill(pid,SIGCONT);
        sleep(3); printf("Parent: Killing child %d\n",pid); kill(pid,SIGKILL);
        wait(NULL); puts("Parent: Child terminated, exiting.");
    }
}


#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    for (int i = 1; i < c; i++) {
        stat(v[i], &s);
        printf("File: %s\nInode: %lu\n", v[i], s.st_ino);
        puts(S_ISREG(s.st_mode) ? "Regular file" :
             S_ISDIR(s.st_mode) ? "Directory" :
             S_ISCHR(s.st_mode) ? "Character device" :
             S_ISBLK(s.st_mode) ? "Block device" :
             S_ISFIFO(s.st_mode) ? "FIFO/Pipe" :
             S_ISLNK(s.st_mode) ? "Symbolic link" :
             S_ISSOCK(s.st_mode) ? "Socket" : "Unknown");
    }
}













(23)

#include <stdio.h>

int main(int c, char *v[]){
    FILE *f = fopen(v[1],"r");
    if(f) printf("File exists\n"), fclose(f);
    else  printf("File not found\n");
}

#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    for (int i = 1; i < c; i++) {
        stat(v[i], &s);
        printf("File: %s\nInode: %lu\n", v[i], s.st_ino);
        puts(S_ISREG(s.st_mode) ? "Regular file" :
             S_ISDIR(s.st_mode) ? "Directory" :
             S_ISCHR(s.st_mode) ? "Character device" :
             S_ISBLK(s.st_mode) ? "Block device" :
             S_ISFIFO(s.st_mode) ? "FIFO/Pipe" :
             S_ISLNK(s.st_mode) ? "Symbolic link" :
             S_ISSOCK(s.st_mode) ? "Socket" : "Unknown");
    }
}





















(24)

#include <stdio.h>
#include <sys/stat.h>

int main(int c, char *v[]) {
    struct stat s;
    for (int i = 1; i < c; i++) {
        stat(v[i], &s);
        printf("File: %s\nInode: %lu\n", v[i], s.st_ino);
        puts(S_ISREG(s.st_mode) ? "Regular file" :
             S_ISDIR(s.st_mode) ? "Directory" :
             S_ISCHR(s.st_mode) ? "Character device" :
             S_ISBLK(s.st_mode) ? "Block device" :
             S_ISFIFO(s.st_mode) ? "FIFO/Pipe" :
             S_ISLNK(s.st_mode) ? "Symbolic link" :
             S_ISSOCK(s.st_mode) ? "Socket" : "Unknown");
        puts("");
    }
}

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t c;
void h(int s){ puts("Timeout! Killing child..."); kill(c,SIGKILL); }

int main(){
    signal(SIGALRM,h);
    if(!(c=fork())) execlp("sleep","sleep","10",0);
    alarm(5);
    int st; wait(&st);
    printf(WIFEXITED(st)?"Child exited normally\n":"Child killed by signal\n");
}















(25)

#include <stdio.h>
int main(){
    freopen("out.txt","w",stdout);
    printf("22+12345= %d",(22+12345));
    printf("This text will be written to the file!\nHello, file redirection works!\n");
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, 1);   // Redirect standard output (stdout) to file
    close(fd);     // Close original file descriptor
    printf("Hello! This goes to output2.txt\n");
}

