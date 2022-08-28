# System call flowchart
USER PROCESS
1. user executing process
2. calls system call (kernel routine) with mode bit 0. This triggers an exception in the user process (trap) which sends it to the OS kernel
3. Wait until system call completes and then read return from system call (synchronous mode)
KERNEL
executes system call and return mode bit 1 to user

To make a system call, an application must:
- write arguments
- save relevant data at well defined location
- make system call

System call arguments can be passed directly to OS or inderectly by loading its address from a register

## Crossing the user/kernel protection boundary
- only the kernel is allowed to perform access to hardware, change allocation to resources for hardware
- hardware provides support for user/kernel transitions
-- e.g., trap son illegal instructions or memory accesses requiring special privelege
-- the result of this trap, is that the hardware initiates transfer of control over to the OS kernel, and marks this by the special privelege bit (0)
-- the OS then checks what caused the trap, and whether to grant or deny the request to cause the trap (based on policies in the OS)
- involves a number of instructions, could take some time (50-100 ns), and switches locality, which affects hardware cache and has impact on application performance. Not cheap!