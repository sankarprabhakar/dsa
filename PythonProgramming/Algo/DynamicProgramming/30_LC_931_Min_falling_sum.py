"""
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

Seen this question in a real interview before?
1/5
"""

class MinFallingSum(object):
    def minFallingPathSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        m = len(matrix)
        n = len(matrix[0])
        dp = [[-9999999999] * n for i in range(m)]
        minimum = 9999999999
        for i in range(n):
            minimum = min(minimum,self.findminfalling(m,n,0,i,dp,matrix))
        return minimum

    def findminfalling(self,m,n,current_row, current_col,dp,matrix):
        #if current_row >= m or current_col < 0 or current_col >= n:
        #    return 0
        if current_row ==  m-1 and current_col >= 0 and current_col < n:
            return matrix[current_row][current_col]
         
        if dp[current_row][current_col] != -9999999999:
            return dp[current_row][current_col]
        minimum = 9999999
        if current_row+1 < m and current_col-1 >= 0:
            down_l = self.findminfalling(m,n,current_row+1,current_col-1,dp,matrix)
            minimum = min(minimum,down_l)
        if current_row+1 < m and current_col < n:
            down_d = self.findminfalling(m,n,current_row+1,current_col,dp,matrix)
            minimum = min(minimum,down_d)
        if current_row+1 < m and current_col+1 < n:
            down_r = self.findminfalling(m,n,current_row+1,current_col+1,dp,matrix)
            minimum = min(minimum,down_r)
        #if minimum == 9999999:
        #    minimum  = 0

        dp[current_row][current_col] = matrix[current_row][current_col] + minimum
        # + min(self.findminfalling(m,n,current_row+1,current_row-1,dp,matrix),self.findminfalling(m,n,current_row+1,current_row,dp,matrix),self.findminfalling(m,n,current_row+1,current_row+1,dp,matrix))
        return dp[current_row][current_col]

if __name__ == "__main__":
    mfs = MinFallingSum()
    data = mfs.minFallingPathSum([[2,1,3],[6,5,4],[7,8,9]])
    print(data)