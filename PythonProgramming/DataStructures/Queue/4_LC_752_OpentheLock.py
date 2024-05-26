'''
 Open the Lock

Solution
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.
 

Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
'''
from collections import deque
from typing import List
class OpentheLock:
    def __init__(self):
        return 
    def getChildren(self,lockstate: str) -> List[str]:
        res = []
        for i in range(4): # increment and decrement number in each position in the give lock state
            state1 = lockstate[:i] + str((int(lockstate[i]) + 1) % 10 ) + lockstate[i+1:]
            state2 = lockstate[:i] + str((int(lockstate[i]) - 1 + 10) % 10 ) + lockstate[i+1:]
            res.append(state1)
            res.append(state2)
        return res
    def OpenLock(self, target : str, deadends : List[str]) -> int: # target string ; dead lockc
        # Solution is to use the DFS to search for target
        # Initialize the Q with "0000"
        # Initialize visited set with deadends
        # While Q is not empty
            # Pop the Q
            # if poped is targer, return turns
            # Generate children of poped element
            # push it to Q if not visited & mark as visited
        # return -1 if Q is empty
        
        if target in deadends or "0000" in deadends:
            return -1
        q = deque()
        q.append(['0000', 0]) # target, turns
        visited = set(deadends)
        while q:
            lock,turns = q.popleft()
            #print(f"value of lock = {lock}, turns = {turns}")
            if lock == target:
                return turns
            for child in self.getChildren(lock):
                if child not in visited:
                    q.append([child, turns+1])
                    visited.add(child)
        return -1

if __name__ == '__main__':
    unlocker = OpentheLock()
    turns = unlocker.OpenLock(target="0202",  deadends=["0201","0101","0102","1212","2002"])
    print(turns)