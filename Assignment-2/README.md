## Assignment 2: Kernel Modules and System Call CSE 330 OS - 1229960136

The following are my configurations:

### Create A Kernel Module
- path: `/home/cse330/proj2/kernel_module` <br>
**Note:** <br>
**1.Although in the reference file: https://www.hitchhikersguidetolearning.com/2018/10/24/passing-data-to-a-kernel-module-module_param/** <br><br>
**it includes `moduleparam.h` it is uneccesary,**
**only `<linux/kernel.h>` and `<linux/module.h>` is needed** <br><br>
**2. Although it shows red curly lines under IDE, it is a must to import `MODULE_LICENSE("GPL");`**

### Create A New System Call
Step1. create a folder named "my_name"
- path: `/home/linux-6.4.11/my_name`

Step 2. Create a c file named "my_syscall.c"
- path: `/home/linux-6.4.11/my_name/my_syscall.c` <br>

        
        #include <linux/kernel.h>


        asmlinkage long __x64_sys_my_syscall(void){
            printk("This is the new system call ChihYi implemented.\n");
            return 0;
        }
        
Step 3. create a corresponding Makefile under "/my_name" <br>
        ```
        obj-y := my_syscall.o
        ```

Step 4. Link objects to linux in linux's Makefile <br>
        ```
        core-y := my_name/
        ```

Step 5. Add new system call to system call table
- path: `/home/linux-6.4.11/arch/x86/entry/syscalls/syscall_64.tbl` <br><br>
        ```
        548     64      my_name                 sys_my_syscall
        ```

Step 6. Register under the syscalls.h file
- path: `/home/linux-6.4.11/include/linux/syscalls.h` <br><br>
        ```
        asmlinkage long sys_my_syscall(void);
        ```

Step 7. Add an entry in generic table
- path: `/linux-6.4.11/include/uapi/asm-generic/unistd.h` <br><br>
        ```
        #define __NR_process_my_name 452
        __SYSCALL(__NR_process_my_name, sys_my_syscall)
        ```

Step 8. Recompile Kernel
        This is where I got so many failures.
        I did not know I need to do `make -j4` again, according to the reference:
        Adding a quick System Call to the Linux Kernel | by Jeremy Philemon | Medium.
        
  - path: `/linux-6.4.11`


        1. create a new name string
                6.4.11CSE330FallNewSystemCall
        2. rebuild the kernel
                sudo make -j4
                sudo make
        3. install modules
                sudo make modules -j4
                sudo make -j4 modules_install install
        
Step 9. Test Userspace
        
1. create a folder name "system_call"
2. create `syscall_in_userspace.c `
3. gcc
4. `./syscall_in_userspace.o; sudo dmesg | tail -n 1`