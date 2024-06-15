"""
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

"""
class MinPath(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        dp = [[-255] * n for i in range(m)]
        return self.getmindownstreamsum(m,n,0,0,dp,grid)
        

    def getmindownstreamsum(self,m,n,start_x,start_y,dp,grid):
        min_down = 9999999999
        min_right = 9999999999
        if dp[start_x][start_y] != -255:
            return dp[start_x][start_y]
        if start_x == m-1 and start_y  == n-1:
            return grid[start_x][start_y]
        if start_x + 1 < m:
            min_down = self.getmindownstreamsum(m,n,start_x+1,start_y,dp,grid)
        if start_y+1 < n:
             min_right = self.getmindownstreamsum(m,n,start_x,start_y+1,dp,grid)
        dp[start_x][start_y] = grid[start_x][start_y] + min(min_down,min_right)
        return dp[start_x][start_y]

if __name__ == "__main__":
    mp = MinPath()
    min_sum = mp.minPathSum([[1,2,3],[4,5,6]])
    print(min_sum)