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