//
// Created by cguo51 on 8/29/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello from the child process!\n");
        execl("/bin/ls", "ls", "-l", NULL); // Replace child with 'ls -l'
        printf("testttttttttttttttt\n");
	perror("execl"); // If execl fails
        exit(1);
    } else {
        // Parent process
        printf("Hello from the parent process!\n");
        wait(NULL);
        printf("Child process has finished.\n");
    }

    return 0;
}

