/*
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int c, char *v[]) {
    if (c!=2) return printf("Usage: %s <file>\n", v[0]),1;

    struct stat s;
    if (stat(v[1],&s)) return perror("stat"),1;

    printf("File: %s\nInode: %lu\nLinks: %lu\nSize: %ld bytes\n",v[1], s.st_ino, s.st_nlink, s.st_size);

    printf("Perms: ");
    for (int i=8;i>=0;i--)
        putchar((s.st_mode & (1<<i)) ? "rwxrwxrwx"[8-i] : '-');
    putchar('\n');

    printf("Access: %s", ctime(&s.st_atime));
    printf("Modify: %s", ctime(&s.st_mtime));
    printf("Change: %s", ctime(&s.st_ctime));
}
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int c,char *v[]){
    struct stat s; stat(v[1],&s);
    printf("File: %s\nInode:%lu Links:%lu Size:%ld\nPerms:", v[1],s.st_ino,s.st_nlink,s.st_size);

    for(int i=8;i>=0;i--) putchar((s.st_mode&(1<<i))?"rwxrwxrwx"[8-i]:'-');
   
    printf("\nAccess:%sModify:%sChange:%s", ctime(&s.st_atime),ctime(&s.st_mtime),ctime(&s.st_ctime));

}

