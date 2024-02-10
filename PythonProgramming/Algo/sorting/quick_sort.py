# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 05:34:44 2024

@author: sanka
"""

## 1. Partition the Array, maintain start and and end inded
## 2. Sort the right partition.
## 3. Sort the left partition.

class QuickSort:
    def __init__(self):
        return 
    def sort(self, array, start, end):
        if start >= end:
            return -1
        partionIndx = self.partition(array,start,end)
        if partionIndx != -1:
            self.sort(array,start,partionIndx-1)
            self.sort(array,partionIndx+1,end)
            
        
    
    def partition(self, array,start,end):
        pivotIndx = start
        #iterator = start
        
        pivot = array[end] ## Make the end index the pivot value
        
        for i in range(start,end):
            if array[i] > pivot:
                array[pivotIndx],array[i] = array[i],array[pivotIndx]
                pivotIndx += 1
        ## swap the pivod index
        array[pivotIndx],array[end] = array[end],array[pivotIndx]
        #print(array)
        return pivotIndx
            
if __name__ == "__main__":
    quicksort = QuickSort()
    unsorted = [9,8,7,2,5,4,99]
    quicksort.sort(unsorted,0,6)
    print(unsorted)
    
    
    unsorted = [9,8,7,55,5,4]
    quicksort.sort(unsorted,0,5)
    print(unsorted)
    
    
    unsorted = [9]
    quicksort.sort(unsorted,0,0)
    print(unsorted)
    
    
    unsorted = [9,10]
    quicksort.sort(unsorted,0,1)
    print(unsorted)
             
        
        
        
