# Assignment-4-1229960136



- `git pull git@github.com:CSE330-FALL-2023/Assignment-4-1229960136.git`
- `git add .`
- `git commit -m "msg"`
- `git push origin main`

1. Initiate a VMA_ITERATOR
    arguments: 
   - name of iterator: `my_iterator`
   - mm_struct (tree root of memory region): `mm`
   - first index: `0`
2. Replace while loop from `for_each_vma()`
    arguments:
    - name of iterator: `my_iterator`
    - pointer of current vma: `vma`
3. Iterate over pages in `vma_struct`
    ```
    for(const auto &page: vma->pages) {
       if(page.pte_present){
           vma_rss += 1;
            if(page.pte_young) {
                vma_wss += 1;
            }
            else{
                vma_swap += 1;
            }
        }
    }
    
    ```      

    - use a by reference method to access each vma pages
    - `page.pte_present = TRUE`: is a rss
    - `page.pte_present = TRUE && page.pte_young = TRUE `: is a wss
    - `page_pte_young = FALSE`: is a swap
