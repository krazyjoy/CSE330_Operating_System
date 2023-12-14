#include <linux/kernel.h>


asmlinkage long __x64_sys_my_syscall(void){
    printk("This is the new system call ChihYi implemented.\n");
    return 0;
}
