'''
Perfect Squares

Solution
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
'''

'''
Solution : use DFS to find the minimal number of perfect squares

Let us take example of n as 15 :
    * 15 can be made from 1, 4,9 (all squares < 15) assume we select 1 - 
    * then we need to find perf squares summing 14.
    * assume again we select 1 .. then for 13 etc ..the search will continue till we find the number or 
    * end number of levels traversed will give the                                      
        : 

'''
from collections import deque
class perfect_square:
    def __init__(self):
        pass

    def get_squares(self,n):
        if n == 1:
            return [1]
        return [x**2 for x in range(1,n) if x**2 <= n ]

    def calculate_perf_square(self,number):
        q = deque()
        count = 0
        q.append([number,count])
        while q:
            n, c = q.popleft()
            #print(n ,c )
            if n == 0:
                return c
            #print(n)
            squares = self.get_squares(n)
            #print(squares)
            #if len(squares) > 0:
            for square in squares:
                if (n-square) >= 0:
                    q.append([n-square, c+1])
            

if __name__ == '__main__':
    ps = perfect_square()
    count = ps.calculate_perf_square(12)
    print(count)
