# -*- coding: utf-8 -*-
"""
Created on Thu Feb  8 05:18:26 2024

@author: sanka
"""

class BubbleSort:
    def __init__(self):
        return
    def sort(self, input_array, order = "asc"):
        no_elements = len(input_array)
        #print(no_elements)
        for k in range(1,no_elements):
           # print(k)
            swapped = False
            for j in range(0,no_elements-k):
                if order == "asc":
                    if input_array[j] > input_array[j+1]:
                        swapped = True
                        input_array[j+1], input_array[j] = input_array[j], input_array[j+1]
                else:
                    if input_array[j] < input_array[j+1]:
                        swapped = True
                        input_array[j+1], input_array[j] = input_array[j], input_array[j+1]
            if swapped == False:
                return input_array
        return input_array
                    
if __name__ == "__main__":
    bubbler = BubbleSort()
    print(bubbler.sort([9,8,7,6,5,4], order = "asc"))
    print(bubbler.sort([9,8,7,6,5,4], order = "dsc"))
    print(bubbler.sort([9], order = "dsc"))
    print(bubbler.sort([9,10], order = "dsc"))