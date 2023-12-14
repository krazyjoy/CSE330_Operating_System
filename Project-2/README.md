# Project-2-1229960136

### git commands
```angular2html
open a empty directory 
git init
git pull git@github.com:CSE330-FALL-2023/Project-2-1229960136.git
git add .
git remote add origin git@github.com:CSE330-FALL-2023/Project-2-1229960136.git
git commit -m "memory_manage"
git push -u origin main
```

### access memory table
sequence of accessing pte:
- task struct -> mm -> vma linked list
- each page in vma linked list exists 5 level page table
  - page global directory
  - page 4th directory
  - page upper directory
  - page middle directory
  - page table
  - (+offset) page

1. access mm: <br>
    `mm = task->mm`
2. access vma via an iterator <br>
    `VMA_ITERATOR(my_iterator, mm, 0);`
3. loop over vma linked list <br>
    `for_each_vma(my_iterator, vma){}`
4. iterate through each page <br>
    `for(unsigned long page=vma->vm_start; page < vma->vm_end; page += PAGE_SIZE){}`
5. inside each page use <br>
    ```
        pgd_t *pgd;
        p4d_t *p4d;
        pud_t *pud;
        pmd_t *pmd;
        pte_t *ptep, pte;
    ```
    4 variables to find the offset for each table and the corresponded value to next offset
    i.e.
    ```
        pgd = pgd_offset(mm, page);
        p4d = p4d_offset(pgd, page);
        pud = pud_offset(p4d, page);
        pmd = pmd_offset(pud, page);
        ptep = pte_offset_map(pmd, page);
    ```
   
### errors encounter
1. early return <br>
    in the project description, if pointers to address is none or bad returns directly <br>
    however, if I implement it this way, most rss will not be accessed due to early return from loop <br>
    therefore, I changed `return` to `continue` instead.
2. typo of pointer name `test_and_clear_bit(_PAGE_BIT_ACCESSED,(unsigned long *)ppte);` <br>
    I think here means "ptep" not "ppte", so I changed to ` test_and_clear_bit(_PAGE_BIT_ACCESSED,(unsigned long *)ptep);`


