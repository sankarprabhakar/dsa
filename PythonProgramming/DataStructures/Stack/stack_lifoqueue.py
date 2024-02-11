from queue import LifoQueue

class stack_lifoq:
    def __init__(self):
        self.stack_lifo = LifoQueue()
    def push(self,data):
        self.stack_lifo.put(data)
    def pop(self):
        return self.stack_lifo.get()
    
    #def peep(self):
    #    return self.stack_lifo[-1]
    #def printStack(self):
    #    items = list(self.stack_lifo)
    #    for item in items:
    #        print(item,end=' ')

# Test Code..
if __name__ == "__main__":
    stack_lifoq = stack_lifoq()
    stack_lifoq.push('a')
    stack_lifoq.push('b')
    stack_lifoq.push('c')
    #stack_lifoq.printStack()

    print(f"\nPoped value is {stack_lifoq.pop()}\n")

    #stack_lifoq.printStack()

   # print(f"\npeeped value is {stack_lifoq.peep()}\n")

