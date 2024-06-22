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
        for i in range(m):
            l = i-1
            r = i+1
            while l > 0 and r < m:
                
        
        
        dp = [[0] * m for i in range(m)]
        diff = 0
        i = 0
        j = 0
        while diff < m:
            i = 0
            j = diff
            diff = diff+1
            while i < m and j < m:
                if i == j:
                    dp[i][j] = 1
                elif i+1 == j:
                    if s[i] == s[j]:
                        dp[i][j] = 2
                else:
                    if s[i] == s[j] and dp[i+1][j-1] != 0:
                        dp[i][j] = dp[i+1][j-1] + 2
                if max_string_len < dp[i][j]:
                    max_string_len = dp[i][j]
                    largest_i = i
                    largest_j = j
                i = i+1
                j = j+1
        #print(dp)
        return s[largest_i:largest_j+1]



    
if __name__ == "__main__":
    lp = LongestPalindrome()
    paling = lp.longestPalindrome("aaaaa") 
    print(paling)    


        