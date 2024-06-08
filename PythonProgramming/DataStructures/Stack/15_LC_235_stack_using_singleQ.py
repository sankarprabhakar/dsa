from collections import deque
class MyStack(object):

    def __init__(self):
        self.q1 = deque()
        #self.q2 = deque()

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.q1.append(x)
        ## rotate till last element
        for _ in range(len(self.q1) -1):
            self.q1.append(self.q1.popleft())

    def pop(self):
        """
        :rtype: int
        """
        if self.q1:
            return self.q1.popleft()
       
        

    def top(self):
        """
        :rtype: int
        """
        if self.q1:
            return self.q1[0]
     

    def empty(self):
        """
        :rtype: bool
        """
        if self.q1:
            return False
        else:
            return True
        
if __name__ == "__main__":
    mys = MyStack()
    mys.push(1)
    mys.push(2)
    print(f"first top = {mys.top()} and pop = {mys.pop()}")

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()