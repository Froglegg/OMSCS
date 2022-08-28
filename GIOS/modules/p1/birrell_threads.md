## Intro
A threads facility allows you to write programs with multiple simulataneous points of execution, synchronizing through shared memory. For writing concurrent programs.

Multiple ligthweight "threads" within a single address space. Some pitfalls (deadlock) are easier to catch than others, others are more "insidious" performance penalties.

A "thread" is a straightforward concept: a single sequential flow of control. In a high level language you normally program a thread using procedures, where the procedure calls follow the traditional stack discipline (LIFO). A single thread is easy.

Multiple threads in a program means that at any instant the program has multiple points of execution, one in each of its threads. The programmer can mostly view the threads as executing siilmataneously, as if the computer were endowed with as many processors as there are threads. The programmer is required to decide when and where to create multiple threads, or to accept such decisions made for him by implementers of libraries or runtime systems. Additionally, the programmer must occasionally be aware that the computer might not in fact execute all his threads simultaneously.

Having threads execute within a "single address space" means that the computer's addressing hardware is configured so as to permit the threads to read and write the same memory locations. In a high-level language, this usually corresponds to the fact that the off-stack (global, or heap) variables are shared among all the threads of the program. Each thread executes on a separate stack call with its own separate local variables.

## Why use concurrency?
With the advent of multiprocessors, we can use threads to take advantage of the available hardware.

Threads are also useful in driving slow devices such as disks, networks, terminals and printers (I/O). In these cases an efficient program can be doing something else while waiting for the next event, such as the completion of a disk transfer or the receipt of a packet from the network. This can be programmed quite easily with threads by adopting an attitude that device requests are all sequential (i.e., they suspend execution of the invoking thread until the request completes), and that the program meanwhile does other work in other threads.

A third source of conurrency is human users. Humans are good at multi-tasking and get offended if their computers can't do the same.

Distributed systems,e.g., shared network servers, where the server is willing to serve requests to multiple clients, is another important source of concurrency. Use of multiple threads allows the server to handle clients' requests in paralell, instead of artificially serializing them (or creating one server process per client, at great expense).

You can also deliberately add concurrency to your programs in order to reduce latency of operations (e.g., returning to caller before re-balancing a balanced tree).

## Design of a thread facility
In general there are four mechanisms: thread creation, mutual exclusion, waiting for events, and some arrangement for getting a trhead out of an unwanted long-term wait (timeout).

### Thread Creation
A thread is created by calling "fork()", giving it a procedure and an argument record. The effect of "fork" is to create a new thread, and start that thread executing asynchronously at an invocation of the given procedure with the given arguments. When the procedure returns, the thread dies.

Usually, fork returns to its caller a handle on the newly created thread. The handle can b epresented to a "join" procedure, which waits for the given thread to terminate, and returns the result fo teh given thread's initial procedure.

### Mutual Exclusion
Threads interact through access to shared memory. In a high level language, this is usually expressed as access to global variables. Since threads are running in paralell, the programmer myst explicitly arrange to avoid errors arising when threads are accessing the shared variables.

The simplest way to do this is a primitive that offers mutual exclusion called "Mutex".

A mutex has two states: locked and unlocked, initially unlocked. The programmer can achieve mutual exclusion of a set of variables by associating them with a mutex, and accessing the variables only from a thread that holds the mutex (i.e., from a thread executing inside a LOCK clause that has locked the mutex).

The simplest form of a mutex is a global variable. But it might be a part of data strcutre (for example a field of a record).

### Condition variables
You can view a mutex as a simple kind of resource scheduling mechanism. The resource being scheduled is the shared memory accessed inside the LOCK clause, and the scheduling policy is one thread at a time.

But often you need to have more complex scheduling policies, which requires the use of a mechanism that allows a thread to block until some event happens.

A condition variable is always assocaited with a particular mutex, and with the data protected by that mutex. Certain procedures such as Wait, Signal, and Broadcast take a condition variables as their arguments, which respectively block threads (wait), signal unlocks a thread, and broadcast tells all other threads that are locked on the same condition variable to wake up.

All this to protect data that is used in a scehduling decision. If a thread wants a resource it locks the mutex and examines the shared data. If the resource is available, it continues. If not, the thead unlocks the mutex and blocks by calling Wait. Later, when some other thread makes the resource available by calling signal or broadcast, the thread wakes up and tries again.

Etc.

### Alerts
Mechanism for interrupting a particular thread, causing it to back out of some long term wait or computation

## Using a mutex: accessing shared data
In a multi-threaded program all shared mutable data must be protected by associating it with some mutex, and you must access the data only from a thread that is holding the associated mutex

## Using a condition Variable: scheduling shared resources
A conditional varible is used when a programmer wants to schedule the way in which multiple threads access some shared resource, and the simple one-at-a-time mutual exclusion provided by mutexes is not sufficient

## Using Fork: working in paralell
On a multi-processor you will want to use “Fork” in order to utilize as many of your processors as you can.

### Pipelining

On a multi-processor, there is one specialized use of additional threads that is particularly valuable. You can build a chain of producer-consumer relationships, known as a pipeline. For example, when thread A initiates an action, all it does is enqueue a request in a buffer. Thread B takes the action from the buffer, performs part of the work, then enqueues it in a second buffer. Thread C takes it from there and does the rest of the work. This forms a three-stage pipeline. The three threads operate in parallel except when they synchronize to access the buffers, so this pipeline is capable of utilizing up to three processors. At its best, pipelining can achieve almost linear speed-up and can fully utilize a multi-processor.

## Using alert: diverting the flow of control
The purpose of alerts is to cause termination of a long running computation or a long- term wait. For example, on a multi-processor it might be useful to fork multiple competing algorithms to solve the same problem, and when the first of them completes you abort the others. Or you might embark on a long computation (e.g. a database query), but abort it if the user clicks a CANCEL button.

## Concluding remarks
Writing concurrent programs has a reputation for being exotic and difficult. I believe it is neither. You need a system that provides you with good primitives and suitable libraries, you need a basic caution and carefulness, etc.