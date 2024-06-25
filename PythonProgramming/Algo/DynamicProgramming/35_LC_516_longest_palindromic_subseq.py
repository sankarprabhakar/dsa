class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_palindrome_subseq = 1
        m = len(s)
        dp = [[0] * m for i in range(m)]
        for i in range(m):
            for j in range(i,m):
                if i == j:
                    dp[i][j] = 1
                else:
                    if s[i] == s[j]:
                        dp[i][j] = 1 + dp[i][j-1]
                    else:
                        dp[i][j] = dp[i][j-1]
                    if dp[i][j] > max_palindrome_subseq:
                        max_palindrome_subseq =  dp[i][j]
        print(dp)
        return max_palindrome_subseq