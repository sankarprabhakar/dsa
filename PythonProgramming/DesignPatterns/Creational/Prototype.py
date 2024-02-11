# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 16:31:23 2024

@author: sanka
"""
import copy

## A Prototype class maints registry of all sample objects it can create
## It can clone any of the registry object by using deepcopy api
## we can update the paramters of the newly closed object as per our need

class Prototype:
    def __init__(self):
        self.objectregistry = {}
    def register_object(self, name, obj):
        self.objectregistry[name] = obj
    def unregister_object(self, name):
        del self.objectregistry[name]
    def clone(self,objname,**kwargs):
        obj = copy.deepcopy(self.objectregistry.get(objname))
        obj.__dict__.update(kwargs)
        return obj

class Car:
    def __init__(self):
        self.name = "Default"
        self.manufacturer = "Default"
        self.year = "Default"
    def __str__(self):
        return f"{self.name}   {self.year} {self.manufacturer}"
    
##
if __name__ == "__main__":
    
    proto = Prototype()
    proto.register_object("Car", Car())
    
    toyo_car = proto.clone("Car",name="Innova",manufacturer="Toyota", year="2002")
    
    print(toyo_car)