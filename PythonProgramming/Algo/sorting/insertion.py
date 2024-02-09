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
        for i in range(1,no_elements): ## Last element will be auto sorted
            element_to_move = array[i]
            ## init at i and move to 0
            j = i-1
            while j >= 0:
                if order == 'asc':
                    if array[j] < element_to_move:
                        array[j+1] = array[j]
                    else:
                        break
                else:
                    if array[j] < element_to_move:
                        array[j+1] = array[j]
                    else:
                        break
                j -= 1             
            array[j+1] = element_to_move
        return array
                
                
                
if __name__ == "__main__":
    insertion = InsertionSort()
    print(insertion.sort([9,8,7,2,5,4,99], order = "asc"))
    print(insertion.sort([9,8,7,55,5,4], order = "dsc"))
    print(insertion.sort([9], order = "dsc"))
    print(insertion.sort([9,10], order = "dsc"))  