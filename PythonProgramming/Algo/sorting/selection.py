# -*- coding: utf-8 -*-
"""
Created on Thu Feb  8 05:34:19 2024

@author: sanka
"""

## Select from the unsorted and place it in already sorted array

class SelectionSort:
    def __init__(self):
        return
    def sort(self, array, order = "asc"):
        no_element = len(array)
        for j in range(no_element - 1): ## 0 to last but one element - As last will auto sorted
            swap_index = j           
            for k in range(j,no_element): ## 0 to last but one element to avoid array out of bound
                if order == "asc":
                    if array[k] < array[swap_index]:
                        swap_index = k
                else:
                    if array[k] > array[swap_index]:
                        swap_index = k
            #print(j,swap_index)
            array[j],array[swap_index] = array[swap_index], array[j]
            #print(array)
        
        return array
    

if __name__ == "__main__":
    selection = SelectionSort()
    print(selection.sort([9,8,7,6,5,4], order = "asc"))
    print(selection.sort([9,8,7,6,5,4], order = "dsc"))
    print(selection.sort([9], order = "dsc"))
    print(selection.sort([9,10], order = "dsc"))         
                    
                        
                