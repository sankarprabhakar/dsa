"""
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
"""
class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_string_len = 1
        m = len(s)
        dp = [[1] * m for i in range(m)]
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
                        dp[i][j] = dp[i][j-1]
                else:
                    if s[i] == s[j]:
                        dp[i][j] = dp[i+1][j-1] + 2
                    else:
                        dp[i][j] = max(dp[i+1][j],dp[i][j-1])
                if max_string_len < dp[i][j]:
                    max_string_len = dp[i][j]
                    largest_i = i
                    largest_j = j
                i = i+1
                j = j+1
            print(dp)
        return  max_string_len



       
if __name__ == "__main__":
    sol = Solution()
    res = sol.longestPalindromeSubseq("aabaa")
    input_str = "aabaa"
    res = sol.longestPalindromeSubseq(input_str)
    print(res)