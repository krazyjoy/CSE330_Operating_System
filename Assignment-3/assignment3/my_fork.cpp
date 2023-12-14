#include <sys/types.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int number = 330;
int main(){
    pid_t pid; // #include <sys/types.h>
    
    std::cout<<"\n Running my_fork.cpp \n"<<std::endl;
    std::cout<<"The initial value of number is "<<number<<std::endl;
    pid = fork();
    // std::cout<<"PID is "<<pid<<std::endl;

    if(pid == 0){
        number += number;
        fork();
        pid_t pidchild = getpid();
        std::cout<<"\t In the child, the number is "<<number<<"-- PID is "<<pidchild<<std::endl;
        return 0;
    }
    else if(pid > 0){
        wait(NULL);
        pid_t pidparent = getpid();
        std::cout<<"In the parent, the number is "<<number<<"-- PID is "<<pidparent<<std::endl;
        return 0;
    }
    else{
        std::cout<<"Fork failed\n";
        return 1;
    }
    return 0;
}