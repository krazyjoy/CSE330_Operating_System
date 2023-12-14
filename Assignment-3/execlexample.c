//
// Created by cguo51 on 8/29/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("\nRunning the execl example\n");
    pid = fork();
    printf("PID is %d\n", pid);

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("\tIn the execl child, PID is %d\n", pid);
        execl("./forkexample2", "forkexample2", NULL); // Replace child with 'ls -l'
        return 0;
    } else {
        // Parent process
        wait(NULL);
        printf("In the parent, done waiting\n");
    }
    return 0;
}

