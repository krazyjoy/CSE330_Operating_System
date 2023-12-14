#include<chrono>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
#include <assert.h>
#include <thread>


using namespace std::this_thread;

sem_t empty;
sem_t full;
sem_t mutex;

const int sz=5;
int buffer[sz] = {};
int fill = 0;
int use = 0;

void put(int value){
    buffer[fill] = value;
    fill = (fill+1) % sz;
}

int get(){
    int tmp = buffer[use];
    use = (use + 1) % sz;
    return tmp;
}


void *producer(void *arg){
    int i;
    for(i=1; i<=10; i++){
        
        sem_wait(&empty);  // deducts empty
        sem_wait(&mutex);  // deducts mutex
        if(fill < 5){
            put(i);
            std::cout<<"produced: "<<i<<std::endl;
        }else{
            std::cout<<"buffer full skipping: "<<i<<std::endl;
        }
        sem_post(&mutex);
        sem_post(&full);
        
    }
    return nullptr;
}


void *consumer(void *arg){
    int i;
    for(i=1; i<=10; i++){
        
        sem_wait(&full);
        sem_wait(&mutex);
        if(use >= 0){
            int task = get();
            std::cout<<"consumed: "<<task<<std::endl;
        }else{
            std::cout<<"buffer empty. "<<use<<std::endl;
        }
        sem_post(&mutex);
        sem_post(&empty);
    }

    return nullptr;
}

int main(int argc, char *argv[]){


    sem_init(&empty, 0, 5);
    sem_init(&full, 0,0);
    sem_init(&mutex, 0, 1);

    pthread_t producer_t, consumer_t;
    int rc=0;

    rc = pthread_create(&producer_t, NULL, producer, NULL);
    assert(rc == 0);
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    rc = pthread_create(&consumer_t, NULL, consumer, NULL);
    
    
    assert(rc == 0);
    
    
    rc = pthread_join(producer_t, NULL);
    rc = pthread_join(consumer_t, NULL);
    assert(rc == 0);

    
    return 0;

}