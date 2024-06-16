"""
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
"""
class UniquePathsWithObstacle:
    def uniquePathsWithObstacles(self, grid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
    
        m = len(grid)
        n = len(grid[0])
        # if dp[i,j] != 0:
        #   return dp[i,j]
        # if we can travel right
        # dp[i,j] = call_recur[i+1, j] + call_recur[i,j+1]
        # if i == m-1 & j == n-1
        #  return 0
        dp = [([0] * n) for i in range(m)]
        #print(dp)
        routes = self.find_routes_from(0,0,m,n,dp,grid)
        return routes
        
    def find_routes_from(self, start_x, start_y, m , n,dp,grid):
        #print(f"x, y = ({start_x} , {start_y})")
        if grid[start_x][start_y] == 1:
            return 0
        if dp[start_x][start_y] != 0:
            return dp[start_x][start_y]
        if start_x == m-1 and start_y == n-1:
            return 1
        
        if start_y + 1 < n:
            dp[start_x][start_y] = dp[start_x][start_y]  +  self.find_routes_from(start_x,start_y+1,m,n,dp,grid)
        if start_x + 1 < m:
            dp[start_x][start_y] = dp[start_x][start_y] +  self.find_routes_from(start_x+1,start_y,m,n,dp,grid)
        return dp[start_x][start_y]
if __name__ == "__main__":
    up = UniquePathsWithObstacle()
    ret = up.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]])
    print(ret)