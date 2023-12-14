#include <iostream>
#include <assert.h>
#include <pthread.h>


static volatile int number = 330;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;


void *my_thread(void *arg){
    std::cout<<(char * )arg<<" : begin (number = "<<number<<" )\n";

    
    pthread_mutex_lock(&counter_mutex);

    number *= 2;

    pthread_mutex_unlock(&counter_mutex);

    

    std::cout<<(char * )arg<<" : done (number = "<<number<<" )\n";
    return NULL;
}
int main(){


    pthread_t p1, p2, p3;
    int rc = 0;
    std::cout<<"main: begin (number = "<<number<<" )\n";

    // first thread
    char arg1[] = "3";
    rc = pthread_create(&p1, NULL, my_thread, arg1);

    rc = pthread_join(p1, NULL); // wait for a thread to terminate
    assert(rc == 0);

    // second thread
    char arg2[] = "2";
    rc = pthread_create(&p2, NULL, my_thread, arg2);

    rc = pthread_join(p2, NULL);
    assert(rc == 0);

    // third thread
    char arg3[] = "1";
    rc = pthread_create(&p3, NULL, my_thread, arg3);

    rc = pthread_join(p3, NULL);
    assert(rc == 0);

    

    pthread_mutex_destroy(&counter_mutex);

    std::cout<<"main: end (number = "<<number<<" )\n";


    return 0;
}