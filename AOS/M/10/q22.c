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

