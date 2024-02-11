# -*- coding: utf-8 -*-
"""
Created on Mon Jan 29 05:14:23 2024

@author: sanka
"""

class Node:
    def __init__(self, val):
        self.value = val
        self.next = None
        self.prev = None
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        return
    def insert(self,val):
        if self.head == None:
            self.head = Node(val)
            return 
        temp = self.head
        while temp.next != None and  temp.value < val: 
            temp = temp.next
    
        
        nn = Node(val)
        if temp == self.head and temp.value > val:
            nn.next = self.head
            self.head.prev = nn
            self.head = nn
        elif temp.next == None and temp.value < val:
            #nn.next = temp
            nn.prev = temp
            temp.next = nn
        else:
            nn.next = temp
            nn.prev = temp.prev
            temp.prev.next = nn
            temp.prev = nn
            
    def delete_node(self, value):
        temp = self.head
        
        while temp.next != None and temp.value != value:
            temp = temp.next
            
        if temp == self.head and temp.value == value:
            self.head = self.head.next
        elif temp.next == None and temp.value == value:
            temp.prev.next = temp.next
        elif temp.next == None and temp.value != value:
            print("Data not found!!")
        else:
            temp.prev.next = temp.next
            temp.next.prev = temp.prev
            
       
            
            
            
    def printList(self):
        temp = self.head
        while temp != None:
            print(f" {temp.value}", end = "-->")
            temp = temp.next
        return 
    
if __name__ == "__main__":
    ll = DoublyLinkedList()
    ll.insert(10)
    ll.insert(11)
    ll.insert(15)
    ll.insert(14)
    ll.insert(1)
    ll.delete_node(15)
    ll.printList()
    
    
    
    """ def delete_node_1(self, value):
      temp = self.head
      if temp.value == value:
          self.head = self.head.next
          return
      
      while temp.next != None and temp.next.value != value:
          temp = temp.next
          
      if temp.next == None and temp.value != value:
          print("Data not found!!")
      else:
          temp.next = temp.next.next
          temp.next.prev = temp
          
          """