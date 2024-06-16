"""
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
Seen this question in a real interview before?
1/5

"""
class MinSumTriangle(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        h = len(triangle)
        dp = [[-99999] * i for i in range(1,h+1)]
        #print(dp)  
        return self.getMinPathSum(h,0,0,triangle,dp) 
    def getMinPathSum(self, max_height, current_height,row_index, triangle,dp):
        
        if current_height == max_height:
            return 0
        if dp[current_height][row_index] != -99999:
            return dp[current_height][row_index]
        if current_height == max_height-1:
            return triangle[current_height][row_index]
        dp[current_height][row_index] = triangle[current_height][row_index] + min(self.getMinPathSum( max_height, current_height+1,row_index, triangle,dp),
        self.getMinPathSum( max_height, current_height+1,row_index+1, triangle,dp))
        return dp[current_height][row_index]
        

if __name__ == "__main__":
    t = MinSumTriangle()
    val = t.minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]])
    print(val)