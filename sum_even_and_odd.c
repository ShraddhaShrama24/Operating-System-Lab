#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid;
    int arr[20], n, status;
    int s_even = 0, s_odd = 0;
    printf("Enter Limit: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    pid = fork();
    if (pid == 0) {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                s_even += arr[i];
            }
        }
        printf("Child: Sum of even numbers = %d\n", s_even);
        exit(0);
    } else {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                s_odd += arr[i];
            }
        }
        wait(&status);  
        printf("Parent: Sum of odd numbers = %d\n", s_odd);
    }
    return 0;
}
