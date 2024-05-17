class my_queue:
    def __init__(self):
        self.myqueue = []
    def enqueue(self, data):
        self.myqueue.append(data)
    def dequeue(self):
        try:
            return self.myqueue.pop(0)
        except:
            return -1
    def printqueue(self):
        for item in self.myqueue:
            print(f" {item } -", end=" ")


if __name__ == "__main__":
    q = my_queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.enqueue(6)
    q.printqueue()
    print(f"Value theat is dequeuesd = {q.dequeue()}")
    print(f" Value taht is dequeued is {q.dequeue()}")
    q.printqueue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
