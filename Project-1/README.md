


# Global Variables: Define my input parameters
1. buffSize:
    - set to MAX_BUFFER_SIZE (500)
2. prod:
    - set to MAX_NO_OF_PRODUCERS (1)
3. cons: 
    - set to MAX_NO_OF_CONSUMERS (100)
4. uuid:
    - set to UUID (33)

- TO pass the input parameters from `insmod` command line, 
   call the function `module_param()` and pass as integer parameters

# Global Variables: Define my semaphores
1. empty: number of empty buffers
2. full: number of full buffers
3. mutex: a mutual semaphore

# __init thread_init_module()
- initialize semaphores: use `sem_init()`, pass semaphores by reference and set them to desired value
**the initialize value can be interpreted as the capacity of threads allowed**
    ```
        sem_init(&empty, buffSize)
        sem_init(&full, 0)
        sem_init(&mutex,1)  ---- 1 is a binary semaphore --- or lock
    ```

- create producer threads
    - To produce producer_thread by different thread name, I use `name_threads();`, which will later replace `X` in `k-producer-X` to respected index
    - Initialize buffer[]: use the struct process_info type to store multiple information (i.e.process pid, start_time, boot_time)
    - use `for()` to generate a sequence of producer threads, bounded by `prod`(the number of producers)
    - use `kthread_run(<PRODUCER_FUNCTION, NULL,PRODUCERS[]>`, to create producer thread contained with `kProducer-X` char[] name
      - PRODUCER_FUNCTION: `producer_thread_function`
      - PRODUCERS[]: `char producers[index][12]`
      - RETURN VALUE: `kthread_run` returns `task_struct` type which contains information required for process descriptor to reference from, for ease
        control, `ctx_producer_thread[]` stores the task_struct list
- create consumer threads
  - use `for()` to generate a sequence of consumer threads
  - use `kthread_run(<CONSUMER_FUNCTION, NULL, CONSUMERS[])`, to create consumer threads

- Error Handling
  - success: `pr_info()` "Module loaded"
  - failed: `PCINFO()` Incorrect Input Parameter Configuration Received...
  - return 0 after init_thread function completes


- producer thread function
  for each process macro iterate through the task list to access each task_struct
    - if the task's uid matches 33, deduct 1 empty buffer and lock the producer write process
    - store process information into buffer
    - increment 1 full pointer and unlock the producer section to allow next awaiting producer threads to enter
- consumer thread function
  - the consumer thread function is slightly different by using `end_flag` and `while(kthread_should_stop)`to control exit function
  -  if no commands call on stopping the thread, the full pointer will be deducted by 1, indicating consume 1 buffer, and
  - a lock will prevent other thread from entrance the rest of function
  - `end_flag` will test if 
    1. total number of process consumed and produced are satisfied
    2. stop the threads finished running its task
    3. the consumer thread function is implemented this way to avoid deadlocks.
  - compute by adding up each process time: `ktime_get_ns()` - `buffer[use].start_time`
  - unlock consumer critical section and increment 1 empty buffer

## kernel module instantiate
`module_init()` & `module_exit()`
the test.sh file is written with test commands


## small debugging techniques
I have many problems in my code, but at first I could not debug because the CPU on virtual machine has devoted
all its power on the module and the `sudo dmesg` cannot even be executed from another terminal
- solution: Before compilation, open another terminal, typed in `sudo dmesg;` and test once to pass the password authentication
- then compile code, and use `up` key to generate `sudo dmesg`. The error message displayed hints the pathway to clear all the mistakes.

        