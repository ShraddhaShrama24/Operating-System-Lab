#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        sleep(6); 
        printf("Child PID : %d and PPID : %d\n", getpid(), getppid());
    }
    printf("Terminating PID : %d\n", getpid());
    return 0;
}
