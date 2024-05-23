# Queues
Queue is a data structure in which follows First in First Out format, that is the first element added will be removed first. 
Queue have two ends namely Rear and Front. Rear end : Where data gets added Front end: where data gets removed

## Queue Operations:
* Enqueue : Operation for adding data to rear end of queue.
* Dequeue : Operation for removing data from the front end of queue
* isEmpty : Operation returns if Queue is Empty or not

## Implementation options:
* C :
  * Arrays
  * LinkedList

* Python:
  * List
  * Collections.dqueue
  * Queue.Queue

* C++
  * Vectors
  * LinkedList

  ## BFS and shortest path finding
   * BFS is used to find the shortest path from root node to given node.
   * Algo:
      1 From the node, add the root to Q & initialized tte depth counter 
      2 Get the size of Q_size
        3 While Q_size is not empty
          * Dequeue from Q:
              * Mark the item as visitied 
              * Enqueu all it neighbours.
              * increment the Depth_counter
        4 Go to step to get #2.
      5 return depth_counter is Q_Size is 0
  

