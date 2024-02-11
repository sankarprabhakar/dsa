from collections import deque

class deque_stack:
    def __init__(self):
        self.stack_deque = deque()
    def push(self, data):
        self.stack_deque.append(data)
    def pop(self):
        return self.stack_deque.pop()
    def peep(self):
        return self.stack_deque[-1]
    def isStackEmpty(self):
        try:
            self.peep()
            return False
        except:
            return True
      
    def printStack(self):
        for item in self.stack_deque:
            print(item,end=' ')

# Test Code..
if __name__ == "__main__":
    deque_stack = deque_stack()
    deque_stack.push('a')
    deque_stack.push('b')
    deque_stack.push('c')
    deque_stack.printStack()

    print(f"\nPoped value is {deque_stack.pop()}\n")

    deque_stack.printStack()

    print(f"\npeeped value is {deque_stack.peep()}\n")


    