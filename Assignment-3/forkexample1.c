//
// Created by cguo51 on 8/29/23.
//
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int number = 7;

int main() {
    pid_t pid;
    printf("\nRunning the fork example\n");
    printf("The initial value of number is %d\n", number);
    pid = fork();
    printf("PID is %d\n", pid);

    if (pid == 0) {
        number *= number;
//        fork();
        printf("\tIn the child, the number is %d -- PID is %d\n", number, pid);
        return 0;
    } else if (pid > 0) {
        wait(NULL);
        printf("In the parent, the number is %d\n", number);
        return 0;
    } else {
        printf("Fork failed\n");
        return 1;
    }
    return 0;
}
