# DSA
Data structures and algorithms

## Stack
A stack is a type of data structure where the last element added is the first one to be removed, following the Last In First Out (LIFO) principle.
### Abstract APIs of the stack data structure
* Push  : Pushes the data to the stack
* Pop   : Remove and return out the recently inserted data.
* Peep  : Returns the last inserted data, but without remove it from stack
* PrintStack : Just print the stack.

### Implementations
* Stack can be implemented in C using 
    * Array
    * Linked list
* Stack can be implemented in python using
    * List - Not thread safe
    * collections.deque - Double ended Queue - Only append and pop is thread safe
    * Queue.LifoQueue - Thread safe

