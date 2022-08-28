# Basic OS services
- scheduler (controls access to CPU(s))
- memory manager (mm, responsible for allocating physical memory to one or more running applications, and makes sure they don't ovverride each others access to memory)
- block device manager (access to disk)
- file system, a higher level abstraction and service

Some linux system calls:
1. Process control
- fork()
- exit()
- wait()
2. File manipulation
- open()
- read()
- write()
- close()
3. Device manipulation
- ioctl()
- read()
- write()
4. Information maintenance
- getpid()
- alarm()
- sleep()
5. Communication
- pipe()
- shmget()
- mmap()
6. Protection
- chmod()
- umask()
- chown()