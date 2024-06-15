"""
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100

"""
class UniquePaths:
    def uniquepath(self,m,n):
        #m = len(grid)
        #n = len(grid[0])
        # if dp[i,j] != 0:
        #   return dp[i,j]
        # if we can travel right
        # dp[i,j] = call_recur[i+1, j] + call_recur[i,j+1]
        # if i == m-1 & j == n-1
        #  return 0
        dp = [([0] * n) for i in range(m)]
        print(dp)
        routes = self.find_routes_from(0,0,m,n,dp)
        return routes
        
    def find_routes_from(self, start_x, start_y, m , n,dp):
        print(f"x, y = ({start_x} , {start_y})")
        if dp[start_x][start_y] != 0:
            return dp[start_x][start_y]
        if start_x == m-1 and start_y == n-1:
            return 1
        if start_y + 1 < n:
            dp[start_x][start_y] = dp[start_x][start_y]  +  self.find_routes_from(start_x,start_y+1,m,n,dp)
        if start_x + 1 < m:
            dp[start_x][start_y] = dp[start_x][start_y] +  self.find_routes_from(start_x+1,start_y,m,n,dp)
        return dp[start_x][start_y]

if __name__ == "__main__":
    up = UniquePaths()
    paths = up.uniquepath(3,2)
    print(paths)
    paths = up.uniquepath(3,7)
    print(paths)

