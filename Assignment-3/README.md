# Assignment-3-1229960136 - Process & Thread & Semaphores

1. Implement a Multi-process program
    - Create a child: `pid = fork();`
      - child's pid is 0
      - parent's pid is none 0
   - Inside a child process create another child: `if (pid == 0) { fork() } `
   - To print the actual pid of a child instead of `0`, use `getpid()`


2. Implement a Multi-threads program
    - Create a thread:
      `pthread_create(&process, NULL, function, arg)`
    - Wait a thread:
      `pthread_join(process, NULL)`
    - Create a lock to avoid mutual access of a function:
        `pthread_mutex_t <lock_name> = PTHREAD_MUTEX_INITIALIZER;`
    - Lock:
       ` pthread_mutex_lock(&<lock_name>);`
    - Unlock:
       `pthread_mutex_unlock(&<lock_name>);`
    - KeyNote: Wrap **global variable** inside a lock
        

3. Implement a producer and consumer prototype with multi-threads
    - Need 3 Semaphores
      1. Keep buffer from being overwriting from producers
        - sem_t full
      2. Keep buffer from being accessed when no tasks exist
        - sem_t empty
      3. Keep `fill` pointer and `use` pointer protected from manipulated in the middle of production/consumption
        - sem_t mutex
    - A circulate buffer to prevent memory explosion
        - use (+1) % size_of_buffer
        - producer needs to know the last `fill` pointer, to write at the next buffer slot
        - consumer needs to know the last `use` pointer, to indicate the next consumable buffer slot
    - Avoid Deadlock producer and consumer waiting for each other
      - wrap **only the get or post** function inside mutex lock, place `full` and `empty` semaphore out of the locks
        - this assures that the producer or consumer checks the full and empty mutex first, instead of waiting for the lock from either side to be released
    
      - KeyNote: Make sure the `std::this_thread::sleep_for()` is in between the `pthread_create(producer_t, NULL, producer, NULL)` <br>
        `pthread_create(consumer_t, NULL, consumer, NULL)`  for a 1-second gap
    - For Semaphores to synchronize:
      1. `sem_wait(s)`
        - deducts the s value 
        - when s.value goes to 0, another thread waits until s.value goes above zero
      2. `sem_post(s)`
        - increase the s value
        - if 1 or more process/thread is waiting, awake one each time
    
        
