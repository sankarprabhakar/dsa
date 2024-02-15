# -*- coding: utf-8 -*-
"""
Created on Thu Feb 15 05:11:03 2024

@author: sanka
"""

# Heap sort
# Array will have two parts sorted and unsorted parts.
# array will have unsorted part at the end of it
# 
# Step 1 : Heapify from root
# Step 2 : Remove root to storted part of array
# Step 3 : Replace root with last element from unsorted and repeat from  Step1 
#          till arry is completely sorted

class heapsort:
    def __init__(self):
        pass
    def sort(self, array):
        self.print_array()(array)
        for i in range(0,len(array)):
            self.heapify_top_down(array, len(array), 0)
        self.print_array(array)
        
        
        pass
    
    def heapify_top_down(self, array,length ,start_index):
        largest = start_index
        left_child = self.getleftchild(largest)
        right_child = self.getrightchild(largest)
        
        if largest < length and array[left_child] > array[largest]:
            largest = left_child
        if largest < length and array[right_child] > array[largest]:
            largest = right_child
        ## Swap largest with 
        if start_index != largest:
            array[start_index], array[largest] = array[largest], array[start_index]
            self.heapify_top_down(array, length, largest)
    
    def print_array(self,array):
        print(array)
        
    def getrightchild(self, n):
        return 2*n + 1
    def getleftchild(self,n):
        return 2*n+2
    def getparent(self,n):
        return ( n - 1 ) //  2