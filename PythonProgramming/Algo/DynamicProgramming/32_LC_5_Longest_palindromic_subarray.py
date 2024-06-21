"""
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
"""
class LongestPalindrome(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        largest_i = 0
        largest_j = 0
        max_string_len = 1
        m = len(s)
        dp = [[0] * m for i in range(m)]
        for i in range(m):
            dp[i][i] = 1
            if i+1 < m and s[i] == s[i+1]:
                dp[i][i+1] = 1
                largest_i = i
                largest_j = i+1
                max_string_len = 1
        for i in range(m): #0,1,2,3
            for j in range(i+2,m): # 2,3 (0,3)  ==> 1 & 2 
                print(f"i = {i} j = {j}")
                if s[i] == s[j] and dp[i+1][j-1] != 0:
                    dp[i][j] = j-i + 1
                    if dp[i][j] > max_string_len:
                        max_string_len = dp[i][j]
                        largest_i = i
                        largest_j = j
        print(dp)
        #print(largest_i,largest_j)        
        return s[largest_i:largest_j+1]
    
if __name__ == "__main__":
    lp = LongestPalindrome()
    paling = lp.longestPalindrome("aaaaa") 
    print(paling)    


        