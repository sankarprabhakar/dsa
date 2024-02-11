# -*- coding: utf-8 -*-
"""
Created on Sun Jan 28 05:56:13 2024

@author: sanka
"""

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None
        return 
    def insert_end(self,value):
        temp = self.head
        if temp == None:
            self.head = Node(value)
            return
        
        while temp.next != None:
            temp = temp.next
            
        temp.next = Node(value)
        return
    
    def insert_head(self,value):
        temp = Node(value)
        temp.next = self.head
        self.head = temp
        return
    
    def insert_inorder(self,value):
        # insert as head ?
        # insert at head
        # insert at tail
        # insert in between.
        
        if self.head == None:
            self.head = Node(value)
            return 
        prev = temp = self.head
        
        while temp != None and temp.value < value:
            prev = temp
            temp = temp.next 
        nn = Node(value)
        if temp == prev:
           nn.next = temp
           self.head = nn
        else:
            nn.next = prev.next
            prev.next = nn
            
    def create_loop_in_linkedlist(self):
        temp = self.head
        while temp.next != None:
            temp = temp.next
        
        temp.next = self.head
            
    
    def length(self):
        temp = self.head
        count = 0
        while temp != None:
            count += 1
            temp=temp.next
        return count
    
    
    def reverse_print(self):
        self.reverse_print_utility(self.head)
        
    def reverse_print_utility(self,root):
        if root == None:
            return
        self.reverse_print_utility(root.next)
        print(f"{root.value}", end ="-->")
        return
    
    def reverse_linked_list(self):
        prev = None
        current = self.head
        next_ptr = None
        while current != None:
            next_ptr = current.next
            current.next = prev
            prev = current
            current = next_ptr
        self.head = prev
        
    def reverse_recursive(self, current, prev):
        if current == None:
            self.head = prev
            return prev
        ret = self.reverse_recursive(current.next, current)
        current.next = prev
        return ret
    
    
    def reverse_recursive_type2(self,root):
        if root.next == None:
           # self.head = root
            return root
        ret = self.reverse_recursive_type2(root.next)
        root.next.next = root
        if root == self.head: ## Adjust head and
            self.head.next = None
            self.head = ret
        return ret
    
    
    def delete_node(self, val):
        # delete head
        # delete tail
        # delete mid
        if self.head == None:
            print("Empty")
            return -1
        temp = prev = self.head
        while temp != None and temp.value != val:
            prev = temp
            temp = temp.next
        if temp == prev:
            self.head = self.head.next
        else:
            prev.next = prev.next.next
            
    def nth_node_fromend(self, node_number):
        front = rear = self.head
        temp = node_number
        while node_number != 0:
            if front!= None:
                front = front.next
                node_number -= 1
            else:
                print(f"Link list doesn't have {temp} nodes")
                return -1
        while front != None:
            front = front.next
            rear = rear.next
        return rear.value
    
    
    def find_middle_node(self):
        fast = slow = self.head
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        
        return slow.value
    
    
    def find_loop_in_linkedlist(self):
        fast = slow = self.head
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                print("Loop detected !!")
                return 
        print("No loops detected!!")
        
        
        
    def printLinkedList(self):
        temp = self.head
        #print("START -->",end= " ")
        while (temp!=None):
            print(f"{temp.value}", end = "-->")
            temp = temp.next
        print("END", end="\n")
            
if __name__ == "__main__":
    #ll = LinkedList()
    #ll.insert_end(1)
    #ll.insert_end(2)
    #ll.insert_end(3)
    
    #ll2 = LinkedList()
    #ll2.insert_head(4)
    #ll2.insert_head(5)
    #ll2.insert_head(6)    
    #ll.printLinkedList()
    #print("\n")
    #ll2.printLinkedList()
    
    print("\n")
    ll3 = LinkedList()
    ll3.insert_inorder(2)
    #ll3.printLinkedList()
    #print("\n")
    ll3.insert_inorder(5)
    ll3.insert_inorder(4)
    ll3.insert_inorder(6)
    ll3.insert_inorder(3)
    ll3.insert_inorder(7)
    ll3.insert_inorder(9)
    ll3.printLinkedList()
    #ll3.reverse_linked_list()
    #ll3.printLinkedList()
    #node = ll3.reverse_recursive(ll3.head, None)
    #node = ll3.reverse_recursive_type2(ll3.head)
    #print(node.value)
    
    #ll3.delete_node(3)
    #ll3.printLinkedList()
    #ll3.create_loop_in_linkedlist() -- This will break every other 
    #functions as list next ends
    #ll3.find_loop_in_linkedlist()
    
    print(f"Nth node from end is {ll3.nth_node_fromend(6)}")
    
    print(f"Middle node = {ll3.find_middle_node()}")
    
    #ll3.reverse_print()