"""
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
"""
from collections import deque
class WordBreak(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        visited = set()
        q = deque()
        q.append(s)
        while q:
            data = q.popleft()
            if data in visited:
                continue
            visited.add(data)
            for word in wordDict:
                if data.startswith(word):
                    reminder  = data[len(word):len(s)]
                    q.append(reminder)
                    if reminder == '':
                        return True
        return False
            

if __name__ == "__main__":
    wb = WordBreak()
    result = wb.wordBreak("leetcode",["leet","code"])
    print(result)