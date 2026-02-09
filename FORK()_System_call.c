#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid;
    printf("Before fork: I am the main process.\n");
    pid = fork();  
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child Process: Hello! My PID is %d and my Parent's PID is %d\n", getpid(), getppid());
    }
    else {
        printf("Parent Process: Hello! My PID is %d and I created a Child with PID %d\n", getpid(), pid);
    }
    return 0;
}
