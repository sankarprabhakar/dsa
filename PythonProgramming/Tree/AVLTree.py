# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 13:55:50 2024

@author: sanka
"""
import math 
from queue import Queue
class AVLNode:
    def __init__(self, val):
        self.value = val
        self.right = None
        self.left = None
        self.height = 0
        

class AVLTree:
    def __init__(self):
        self.root = None
        
    def insert(self, root, value):
        if root == None:
            temp = AVLNode(value)
            if self.root == None:
                self.root = temp
            return temp
        if value < root.value:
            ## insert left
            root.left = self.insert(root.left,value)
        else:
            root.right = self.insert(root.right, value)
        
        ### Adjust the height
        height = max(self.height(root.left),self.height(root.right))+ 1
        root.height = height
        balance_factor = self.height(root.left) - self.height(root.right)
        
        
        if balance_factor > 1 and value < root.left.value:
            return self.rotateRight(root)
        if balance_factor < -1 and value > root.right.value:
            return self.rotateLeft(root)
        
        if balance_factor > 1 and value > root.left.value:
            root.left = self.rotateLeft(root.left)
            return self.rotateRight(root)
        if balance_factor < -1 and value < root.right.value:
            root.right = self.rotateRight(root.right)
            return self.rotateLeft(root)
        
        return root
        
        
    def rotateLeft(self,parent):
        #print(parent.value)
        rotatecenter        = parent.right
        rotatecenterleft   = rotatecenter.left
        rotatecenter.left  = parent
        parent.right         = rotatecenterleft
        
        parent.height = max(self.height(parent.left), self.height(parent.right)) + 1
        rotatecenter.height = max(self.height(rotatecenter.left), self.height(rotatecenter.right)) + 1
        return rotatecenter
    
    def rotateRight(self,parent):
        #print(parent.value)
        rotatecenter        = parent.left
        rotatecenterright    = rotatecenter.right
        rotatecenter.right   = parent
        parent.left         = rotatecenterright
        
        parent.height = max(self.height(parent.left), self.height(parent.right)) + 1
        rotatecenter.height = max(self.height(rotatecenter.left), self.height(rotatecenter.right)) + 1
        
        return rotatecenter
        
    ####################################################
    #  level order traversal
    ####################################################
    # 1. enque root to Q
    # 2. while Q is not emply - Take item from Q
    #       2.a Print Value of node
    #       2.b Enqueue the children of node to Q
    
    def level_order_traversal(self):
        if self.root == None:
            return
        q = Queue()
        q.put(self.root)
        while q.empty() != True:
            level_size = q.qsize()
            
            while level_size != 0:            
                node = q.get()
                print(f"{node.value}", end= " - ")
                if node.left != None:
                    q.put(node.left)
                if node.right != None:
                    q.put(node.right)
                level_size = level_size - 1
            print("\n---------------------------")
        
        
        
        
        
    def height(self,root):
        if root == None:
            return -1
        return root.height
        #return math.max(self.height(root.left), self.height(root.right)) + 1
    

if __name__ == "__main__":
    print("Hello")
    avl = AVLTree()
    
    avl.root = avl.insert(avl.root, 1)
    avl.root = avl.insert(avl.root, -22)
    avl.root = avl.insert(avl.root, 13)
    #avl.level_order_traversal()
    avl.root = avl.insert(avl.root, 4)
    avl.root = avl.insert(avl.root, 45)
    avl.root = avl.insert(avl.root, 76)
    avl.root = avl.insert(avl.root, 897)
    avl.root = avl.insert(avl.root, 8)
    avl.root = avl.insert(avl.root, 9)
    avl.root = avl.insert(avl.root, 10)
    avl.level_order_traversal()
    