# -*- coding: utf-8 -*-
"""
Created on Thu Feb  8 05:57:49 2024

@author: sanka
"""

## Array will have sorted and unsorted partition
## element from unsorted will be moved to sorted after making appropriate spac
## for sorted element.

class InsertionSort:
    def __init__(self):
        return
    def sort(self,array, order="asc"):
        no_elements = len(array)
        for i in range(no_elements-1): ## Last element will be auto sorted
            element_to_move = array[i]
            ## init at i and move to 0
            j = i
            while j >= 0:
                if array[j] > element_to_move:
                    array[j+1] = array[j]
                else:
                    break
                j -= 1
            array[j] = element_to_move
            
                
                
        