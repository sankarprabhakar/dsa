"""
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
"""
class MaximalSquare(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m = len(matrix)
        n = len(matrix[0])
        dp = [[0] * n for i in range(m)]
        self.getadjacentsquares(m,n,0,0, dp,matrix)
        area = max(max(sublist) for sublist in dp)
        area = area * area
        return area
    def getadjacentsquares(self,m,n,current_row,current_col, dp,matrix):
        if current_row >= m  or current_col >= n:
            return 0
        if dp[current_row][current_col] != 0:
            return dp[current_row][current_col] 
        d = self.getadjacentsquares(m,n,current_row+1,current_col, dp,matrix)
        r = self.getadjacentsquares(m,n,current_row,current_col+1, dp,matrix)
        l = self.getadjacentsquares(m,n,current_row+1,current_col+1, dp,matrix)
        if matrix[current_row][current_col] == '1':
            dp[current_row][current_col]  = 1 + min(d,r,l)
        return dp[current_row][current_col]

        
if __name__ == "__main__":
    ms = MaximalSquare()
    area = ms.maximalSquare([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])
    print(area)