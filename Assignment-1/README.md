# Assignment-1-1229960136

My string `CSE330Fall2023ChihYiHuang`

## Issue that I encountered ...
On step 10., when I execute `make -j4`, I receive error message `No space left on device`.
The situation is wierd in that, I have allocated 100GB and according to my friend who has succeeded building the kernel, build a kernel requires only 30~40GB.

I check the free disk memory using `df -h`, and my 100GB did not appear in list, but my vm do have this much of capacity (call `cfdisk`)

The next step I did was to do filesystem mounting. (https://www.digitalocean.com/community/tutorials/how-to-partition-and-format-storage-devices-in-linux)

- look for a disk of the correct size that has no associated partitions:
  ```
  lsblk
  ```
- partition new drive
  ```
  sudo parted /dev/sda mklabel gpt
  ```
- create a new partition
  ```
  sudo parted -a opt /dev/sda mkpart primary ext4 0% 100%
  ```

- check if new partition is available
  ```
  lsblk
  ```
- initialize Ext4 filesystem with `mkfs.ext4` utility, add a partition label with `-L` flag, select the partition just created (`/dev/sda`)
  ```
  sudo mkfs.ext4 -L datapartition /dev/sda1

  ```

- mount new filesystem (mount drive under `/mnt/data`)
  ```
  1. sudo mount -o defaults /dev/sda1 /mnt/data
  2. sudo nano /etc/fstab
  3. sudo moount -a
  ```
- test the mound (exclude tmpfs)
  ```
  df -h -x tmpfs
  ```

However, when I come to the next step on the instructon pdf file, `make modules -j4`, space is once again full even though I have 64GB of space on filesystem when call `df -h`

------------------------------------------------------------------------------------
## My Problem Resolved
After demo to the TA, the TA found my problem evetually.
The problem was that I download **a new version of ubuntu iso file (23.04)**, this cause the space on disk not allocated directly to filesystem.
At the end, I simply remove all the old machines and locate 22.04 ubuntu to vm.

## The below are some settings I used for setting up a kernel...

BASE MEMORY: 11000MB <br>
PROCESSOR: 4 CPUs <br>
STORAGE: 200GB <br>

Step 3. compile and install a new kernel ...
1. download long-term stable kernel 6.4.11 (to /home/joy)
`wget https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/snapshot/linux-6.4.11.tar.gz`
2. uncompress
`tar -xvf linux-6.4.11`
3. install necessary dependencies
`sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison`
4. copy existing kernel config from existing system to kernel tree
  - kernel config file: /boot/config-$(uname -r)
  - `cd linux-6.4.11`
  - `sudo cp -v /boot/config-$(uname -r)`
5. bring up cores:
`make oldconfig -j4`
6. prompt config changes by `make menuconfig`
7. In kernel configuration window, append string to kernel version
```
General setup -> Local version - append to kerenel release
```
8. Check if multiprocessing is turned on,
```
  Processor type and features - Symmetric multi-processing support - CSE330Fall2023ChihYiHuang
```
9. Disable the conflicting security certificates by executing the two commands below:
```
scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --disable SYSTEM_REVOCATION_KEYS
```

10. Build kernel
`make -j4`

11. Check if kernel is ready
`make`

12. Build the modules
`sudo make modules -j4`

13. Install new kernel modules
`sudo make modules_install -j4`

14. Install new kernel image
`sudo make install -j4`

16. Configure GRUB boot-loader
`sudo update-grub`

17. Restart Linux
`sudo reboot`

18. change GRUB file to see the GRUB menu everytime after reboot
`cd ~/etc/default`
`sudo nano grub`
change `GRUB_TIMEOUT = -1`

19. reboot the system again
`sudo reboot`

20. Upon next login, check running kernel version
`uname -a`

21. show GRUB window
`choose advanced options for ubuntu`
`Ubuntu, with Linux 6.4.11CSE330Fall2023ChihYiHuang`
--------------------------------------------------------------------------------
