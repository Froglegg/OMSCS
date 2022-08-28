# OS Elements
Abstractions:
- process, thread: correspond to operations OS executes
- file, socket, memory page (correlate to hardware devices, storage devices like disks, network cards for sockets, memory for memory page)
Mechanisms:
- create, scehdule
- open, write, allocate
Policies:
- determines exactly how these mechanisms will be used
- e.g., least-recently-used (LRU)
## Memory management example
Abstraction: memory page
Mechanism: allocate, map to a process
Allocates page to DRAM, map that page to a process
Over time, the page may be moved across locations in physical memory or stored on disk if we need to make room
Policies: least recently used (LRU), decide whether the contents of the page will be stored in physical memory or stored on disk (swapped from physical memory to disk if the page hasn't been accessed in a while)

## Design principles
1. Seperation of mechanism and policy
- implement flexible mechanisms to support many polcieis, e.g., LRU (least recently used), LFU (least frequently used), random... in different settings, different policies make sense
2. Optimize for common case
- where will the OS be used?
- what will the user want to execute on that machine?
- what are the requirements of the workload
Understand the common case, and pick the policy that makes the most sense

## User / Kernel Protection Boundary
- The OS must have special privelages to access hardware (priveleged mode is kernel-level privelege, mode bit = 0)
- Unpriveleged mode is user-level (mode bit = 1)
User-kernel switch is supported by hardware:
- Trap instructions
- system calls (open(file), send(socket), mmap(memory))
- signals (OS passes notifications into the applications)

