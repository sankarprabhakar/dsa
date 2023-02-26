# Stack class that implements the 

class my_stack_impl:
    def __init__(self):
        self.stack_list = []
    def push(self, data):
        self.stack_list.append(data)
    def pop(self):
        return self.stack_list.pop()
    def Peep(self):
        return self.stack_list[-1]
    def printStack(self):
        for item in self.stack_list:
            print(item,end=' ')


# Test Code..
if __name__ == "__main__":
    list_class = my_stack_impl()
    list_class.push('a')
    list_class.push('b')
    list_class.push('c')
    list_class.printStack()

    print(f"\nPoped value is {list_class.pop()}\n")

    list_class.printStack()

    print(f"\npeeped value is {list_class.Peep()}\n")

