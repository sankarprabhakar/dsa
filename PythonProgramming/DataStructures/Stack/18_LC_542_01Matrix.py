"""
01 Matrix

Solution
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
"""

"""Soluiton is similar to tat of wall and gates problem"""

from collections import deque
class ZeroOneMatrix:
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
    
         
        myQ = deque()
        m = len(mat)
        n = len(mat[0])
        output = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    myQ.append((i,j))
        ## Q is not empty
        directions = [-1,0,1,0,-1]
        distance = 0
        while myQ:
            distance = distance + 1
            qsize = len(myQ)
            for q in range(qsize):
                pop_data = myQ.popleft()
                for i in range(4):
                    nxt_row = pop_data[0] + directions[i]
                    nxt_colr = pop_data[1] + directions[i+1]
                    if nxt_row < m and nxt_row >=0 and nxt_colr < n and nxt_colr >=0 and mat[nxt_row][nxt_colr] == 1:
                        output[nxt_row][nxt_colr] = distance
                        mat[nxt_row][nxt_colr] = 5 # Marking as visited
                        myQ.append((nxt_row,nxt_colr))
        return output

if __name__ == "__main__":
    matrix = ZeroOneMatrix()
    myout = matrix.updateMatrix(mat=[[0,0,0],[0,1,0],[0,0,0]])
    print(myout)






