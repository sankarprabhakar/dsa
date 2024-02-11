# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 07:26:21 2024

@author: sanka
"""

# The Iterator pattern is a behavioral design pattern that provides a way
# to access the elements of an aggregate object sequentially without 
# exposing its underlying representation. 
# It allows traversal of elements in a collection without exposing 
# its internal structure.

## In python Iterator classes .. it need to install __iter__ and __next__ methods
class Iterator:
    def __init__(self, collection):
        self.collection = collection
        self.index  = 0
    def has_next(self):
        return self.index < len(self.collection)
    def __iter__(self):
        return self
    def __next__(self):
        if self.has_next():
            value = self.collection[self.index]
            self.index = self.index + 1
            return value
        else:
            raise StopIteration
##########################################################

class ListAggregator():
    def __init__(self):
        self.collection = []
   
    def __iter__(self): ## for python iter protocal
        return Iterator(self.collection)
    def add_item(self, item):
        self.collection.append(item)
##########################################################

if __name__ == "__main__":
    list_agg = ListAggregator()
    list_agg.add_item(5)
    list_agg.add_item(6)
    list_agg.add_item(7)
    list_agg.add_item(8)
    list_agg.add_item(8)    
    for i in list_agg:
        print(i, end = " ")
    