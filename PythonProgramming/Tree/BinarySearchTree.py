# -*- coding: utf-8 -*-
#import collections 
import math
class BinaryNode:
    def __init__(self,val):
        self.value = val
        self.left = None
        self.right = None
    def __str__(self):
        return str(self.value)
    
        

class BST:    
    def __init__(self):
        self.root = None
        
    ####################################################
    #  Insert node - Iterative solutio                 #
    ####################################################
        
    def insert(self,val):
        if self.root == None:
            self.root = BinaryNode(val)
            return 
        ## if we have more nodes
        prev = temp = self.root
        while(temp != None):
            prev = temp
            if temp.value > val:
                temp = temp.left
            else:
                temp = temp.right
        if prev.value > val:
            prev.left = BinaryNode(val)
        else:
            prev.right = BinaryNode(val)
        return
         
     ####################################################
    #  Insert node - Iterative solutio                 #
    ####################################################
    
    def recursive_insert(self,val):
        self.root = self.insert_recur(self.root,val)
        
    def insert_recur(self,root,val):
         if root == None:
            root = BinaryNode(val)
            return root
         if root.value < val:
             root.right = self.insert_recur(root.right, val)
         else:
             root.left = self.insert_recur(root.left, val)
         return root
     ####################################################
     #  search node - recursive solutio                 #
     ####################################################
     
    def search_recur(self,root,val):
        if root == None:
            return False
        if root.value == val:
            return True
        if root.value < val:
            return self.search_recur(root.right,val)
        else:
            return self.search_recur(root.left,val)
        
     ####################################################
     #  search node - Iterative solutio                 #
     ####################################################
     
    def search(self,val):
        if self.root == None:
            return False
        temp = self.root
        while temp != None:
            if temp.value == val:
                return True
            elif temp.value < val:
                temp = temp.right
            else:
                temp = temp.left
        return False
     ####################################################
     #  Find Max - Iterative solutio                 #
     ####################################################
     
    def findMax(self):
        if self.root == None:
            return -1
        temp = self.root
        while temp.right != None:
                temp = temp.right
        return temp.value
    
    ####################################################
    #  Find Max - Iterative solutio                 #
    ####################################################
     
    def findMin(self):
        if self.root == None:
            return -1
        temp = self.root
        while temp.left != None:
                temp = temp.left
        return temp.value
    
    ####################################################
     #  Find Max - Iterative solutio                 #
     ####################################################
     
    def findMax_recur(self,root):
        if root == None:
            return -1
        if root.right == None:
            return root.value
        return self.findMax_recur(root.right)
    
    ####################################################
    #  Find Max - Iterative solutio                 #
    ####################################################
     
    def findMin_recur(self,root):
        if root == None:
            return -1
        if root.left == None:
            return root.value
        return self.findMax_recur(root.left)
    
    
    ####################################################
    #  in-order traversal           #
    ####################################################
     
    def inorder(self,root):
        if root == None:
            return
        self.inorder(root.left)
        print(f"{root.value}" , end = " - ")
        self.inorder(root.right)
        
    ####################################################
    #  in-order traversal           #
    ####################################################
     
    def preorder(self,root):
        if root == None:
            return
        print(f"{root.value}", end = ' - ')
        self.preorder(root.left)
        #print(f"{root.value}")
        self.preorder(root.right)
        
    ####################################################
    #  in-order traversal           #
    ####################################################
     
    def postorder(self,root):
        if root == None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print(f"{root.value}", end = ' - ')
        
    ####################################################
    #  isBST - Check if a given tree is binary or not  #
    ####################################################
    # 1. Value in left sub tree must be less thatn value at root
    # 2. Value in right sub tree must be greater thank value at root
    # 3. Left sub tree must be a BST
    # 4. Right sub tree must be a BST
    def isBST(self,root):
        if root == None:
            return True
        if self.isSubTreeValueLesser(root.left,root.value) == True and \
           self.isSubTreeValueGreater(root.right,root.value) == True and \
           self.isBST(root.left) == True and \
           self.isBST(root.right) == True:
               return True
        return False
    
    def isSubTreeValueLesser(self,root,value):
        if root == None:
            return True
        if root.value < value and\
        self.isSubTreeValueLesser(root.left, value) == True and \
        self.isSubTreeValueLesser(root.right, value) == True:
            return True
        return False
    
    def isSubTreeValueGreater(self,root,value):
        if root == None:
            return True
        if root.value > value and\
        self.isSubTreeValueGreater(root.left, value) == True and \
        self.isSubTreeValueGreater(root.right, value) == True:
            return True
        return False
    ####################################################
    #  isBST - MinMax approach
    ####################################################
    # 1. given root must be bounded between min and max controlled from parent value
    # 2. Left sub tree must be a BST
    # 3. Right sub tree must be a BST
    
    def isBST_minmax_util(self):
        return self.isBST_minMax(self.root, math.MIN, math.MAX)
   
    def isBST_minMax(self, root, min_val,max_val):
        if root == None:
            return True
        if root.value > min_val and root.value < max_val and\
           self.isBST_minMax(root.right,root.value,max_val) and \
                self.isBST_minMax(root.left, min_val, root.value):
            return True
        else:
            return False
        
    ####################################################
    #  delete - a node
    ####################################################
    # 1. if lead delete
    # 2. if either or left and right are null. Estabilish a connection from 
    #    right/left to parent of to be deleted node.
    # 3. if it has two children, pick the largest in the right sub tree. and
    #    reduce the problem to #1 or #2 case
    
    def delete_node(self, node , val):
        if node == None:
            return node
        if node.value > val:
            node.left = self.delete_node(node.left, val)
            ## return node moved to end
        elif node.value < val:
            node.right = self.delete_node(node.right, val)
            ## return node --> moved to end
        else:
            ## this is the value to be deleted
            if node.left == None and node.right == None:
                return None
            elif node.left == None:
                return node.right
            elif node.right == None:
                return node.left
            else:
                ## both nodes are there.
                rightTreeSuccessor = self.FindMaxNode(node.right)
                node.value = rightTreeSuccessor.value
                node.right = self.delete_node(node.right, rightTreeSuccessor.value)
                return node
        return node # in not changes in nod assingn ment second and third if else
            
            
    def FindMaxNode(self,node):
        while node.left != None:
            node = node.left
        return node
    
    
    ####################################################
    #  find inorder predecissor and successor - a node
    ####################################################
    # 1. search for Node from root. While going down the tree keep 
    # track for ancestor node.
    #   1.a : If we take right of ancestor node then ancestor
    # can be a possible predicessor.
    #   2.b : If we take left of ancestor node then ancestor
    # can be a possible successor
    # 2. once we reach node. 
    #   2.a.Successsor is minvalue in the right sub tree
    #   2.b. Predicessor is maxvalue in the left sub tree
    def find_inorder_predecessor_successor(self,val):
        pass
   
                
                    
            
            
    
    
    
    
    def print(self):
        temp = self.root
        while (temp != None):
            print(temp)
            temp = temp.right
    
if __name__ == "__main__":
    bst = BST()
    bst.insert(1)
    bst.insert(2)
    bst.insert(3)
    bst.insert(4)
    bst.insert(5)
    bst.recursive_insert(6)
    bst.recursive_insert(7)
    bst.insert(99)
    bst.insert(-122)
    bst.insert(55)
    #print(bst.search_recur(bst.root,7))
    
    #print(bst.search(7))
    print(bst.findMax())
    print(bst.findMin())
    bst.print()
    print("In-order traversal")
    bst.inorder(bst.root)
    print("\npre-order traversal")
    bst.preorder(bst.root)
    print("\npost-order traversal")
    bst.postorder(bst.root)
    #print()
    print ( f"\nIsBST : {bst.isBST(bst.root)}")
    print ( f"IsBST-2 : {bst.isBST(bst.root)}")
    
    bst.root = bst.delete_node(bst.root, 1)
    print("In-order traversal")
    bst.inorder(bst.root)
    
    
    
    
    
        


    