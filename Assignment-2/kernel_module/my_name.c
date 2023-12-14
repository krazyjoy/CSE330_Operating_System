
#include <linux/module.h>
#include <linux/kernel.h>

static int Intparameter = 0;
module_param(Intparameter, int, 0644);

static char* Charparameter = "default";
module_param(Charparameter, charp, 0644);

int my_name(void){
  printk("Hello I am ChihYi, a student of CSE330 %s %d\n", Charparameter, Intparameter);
  return 0;
} 

int hello_init(void){
    printk("Hello World!\n");
    return 0;
}


void hello_exit(void){
    printk("Goodbye World!\n");
}



module_init(my_name);
module_exit(hello_exit);

MODULE_LICENSE("GPL");


