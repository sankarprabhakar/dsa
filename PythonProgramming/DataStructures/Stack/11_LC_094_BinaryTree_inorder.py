# Definition for a binary tree node.
class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right
from collections import deque
class Solution:
    def inorderTraversal(self, root):
        inorder_traversal = []
        stack_inorder = deque()
        #stack_inorder.append(root)
        #last_visited = None
        while root != None or stack_inorder:
            if root != None:
                stack_inorder.append(root)
                root = root.left
            else:
                root = stack_inorder.pop()
                inorder_traversal.append(root.val)
                #stack_inorder.append(poped_data.right)
                root = root.right
                
        return inorder_traversal

if __name__ == '__main__':
    t3 = TreeNode(3,None,None)
    t2 = TreeNode(2,t3,None)
    t1 = TreeNode(1,None,t2)
    io = Solution()
    print(f"inorder  = {io.inorderTraversal(t1)}")




