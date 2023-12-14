# Project-3-1229960136

## filesystem management

### Define proc fs file operations
- TODO 5: Assign correct function pointers to correct functions
```angular2html
.proc_read = read_from_kernel,
.proc_write = write_to_kernel
```
The member of `struct proc_ops` defines proc file system operations, <br>
`read_from_kernel` and `write_to_kernel` are given function name,<br>
whereas `.proc_read` and `.proc_write` tells where a proc <br>
should look at when doing
file read and file write in a kernel


### Define proc fs entries
 - TODO 6: Create a proc entry at /proc/my_proc_file

In `#include <linux/proc_fs.h>`, `proc_create` creates a proc entry by taking
the `name`: name of the proc entry, `mode`: access mode for the proc entry, <br>
`parent directory`: the directory under `/proc`, if there is no directory, set to `NULL` <br>
`proc_ops`: the structure of operations defined 

    
    my_proc_entry = proc_create("my_proc_file", 0, NULL, &proc_operations);
    


### Copy content from kernel buffer to user buffer

    copy_to_user(user_buffer, &kernel_buffer[*ppos], count);
    
The `copy_to_user` function takes `ubuf`: as where the read data need to be stored, <br>
`buff` as buffer in kernel, in my case, is defined as `kernel_buffer` in the original global scope, <br>
and `len` is the length of characters to read


### Copy content from user buffer to kernel buffer
 
    copy_from_user(&kernel_buffer[*ppos], user_buffer, count);
 
Copy data from userspace to kernel space in the proc filesystem, where `ppos` is the position of data,


### Remove proc entries

    remove_proc_entry("my_proc_file", NULL);


The proc entry name is `my_proc_file`, and there is no parent directory under `proc`



### BONUS: write beyond size limit
- TODO Bonus 1:  check if the user is trying to write more than MAX_MESSAGE_SIZE bytes
    
        if(*ppos >= MAX_MESSAGE_SIZE){
            return -EINVAL;
        }

### BONUS: read from tail
- TODO Bonus 2:

        count = min(count, (size_t)(strlen(kernel_buffer) - *ppos));

    message length should be the buffer length deduct by the reading position (*ppos)
    to read until the end of buffer length
