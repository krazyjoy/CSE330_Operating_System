cmake_minimum_required(VERSION 3.23)
project(cse330 C)

set(CMAKE_C_STANDARD 11)

add_executable(test_execl
        test_execl.c)

add_executable(execlexample
        execlexample.c)

add_executable(forkexample1
        forkexample1.c)

add_executable(forkexample2
        forkexample2.c)