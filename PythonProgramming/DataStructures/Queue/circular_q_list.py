class my_cir_queue:
    def __init__(self,size):
        self.myqueue = [i for i in range(size)]
        self.qsize = size 
        self.rear = self.front = -1
        print(self.myqueue)
    def enqueue(self, data):
        ## rear + 1 is haed is full
        if ( self.rear + 1 ) % self.qsize == self.front:
            print("Q is full ")
            return False # Queue full
        #if empty then move head as well
        if self.isEmpty():
            self.front += 1
        self.rear = ( self.rear + 1 ) % self.qsize
        
        self.myqueue[self.rear] = data
        print(self.myqueue)
        return True
    def isEmpty(self):
        if self.rear == self.front == -1:
            return True #self.front += 1
        return False
    def dequeue(self):
        if self.isEmpty():
            print("Q is empty")
            return False
        data = self.myqueue[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = ( self.front + 1 ) % self.qsize
        ## check if Q became empty
        #if self.front > self.rear:
        #    self.front = self.rear = -1 # set front and rear to -1
        return data
    def printqueue(self):
        if self.isEmpty():
            print("Q is empty \n")
        elif self.rear > self.front:
            for i in range(self.front, self.rear+1):
                print(f"{self.myqueue[i]} - ", end=" ")
        else:
            for i in range(self.front,self.qsize):
                print(f"{self.myqueue[i]} - ", end=" ")
            for i in range(0,self.rear+1):
                print(f"{self.myqueue[i]} - ", end=" ")

        #    print(f" {self.myqueue[i] } -", end=" ")
            


if __name__ == "__main__":
    q = my_cir_queue(5)
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.enqueue(6) ## Check Q Full
    q.printqueue()
    print(f"\n Value theat is dequeuesd = {q.dequeue()}", end="\n")
    print(f" Value taht is dequeued is {q.dequeue()}", end = "\n")
    q.printqueue()