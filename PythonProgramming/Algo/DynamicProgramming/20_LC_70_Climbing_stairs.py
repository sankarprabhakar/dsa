"""
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
"""
# Solution  let dp[x] = Be the number of ways we can climp till step x.
# dp[0] = 0
# dp[1] = 1
# dp[2] = 2  -- > (dp[1] + 1step, + dp[0]+2step) ==? dp[1] + dp[2].. i.e one step from step 1 or 2 step from 0th step.
# dp[3] = 3   --> dp[2]+1step, dp[1]+2step =  dp[2] + dp[1] ?
# dp[4] = 5  --> dp[3] + 1 step (one way) + dp[2] + 2 step(oneway)
# dp[n] = 8  -->  dp[n-1] + dp[n-2]  :: We get here from 2 ways

class ClimbStairs:
    def climbing_stairs(self,n):
        dp = [1] * (n+1) 
        #dp[0] = 1  dp[0] = 1 no of ways to climb 0steps is 1 ( not climbing at all)
        #dp[1] = 1  Number of ways of climbing step 1 is 1
        for i in range(2,n+1):
            dp[i] = dp[i-1] + dp[i-2] # 
        return dp[n]

if __name__ == "__main__":
    cs = ClimbStairs()
    ways = cs.climbing_stairs(2)
    print(ways)
