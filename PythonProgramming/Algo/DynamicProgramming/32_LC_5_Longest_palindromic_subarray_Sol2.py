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
            while l >= 0 and r < m and s[l] == s[r]:
                curr_length = r - l + 1
                if curr_length > max_string_len:
                    max_string_len = curr_length
                    largest_i = l
                    largest_j = r
                l = l-1
                r = r+1
            l = i
            r = i+1
            while l >= 0 and r < m and s[l] == s[r]:
                curr_length = r - l + 1
                if curr_length > max_string_len:
                    max_string_len = curr_length
                    largest_i = l
                    largest_j = r
                l = l-1
                r = r+1    
        return s[largest_i:largest_j+1]


if __name__ == "__main__":
    lp = LongestPalindrome()
    paling = lp.longestPalindrome("aaaa") 
    print(paling)    


        