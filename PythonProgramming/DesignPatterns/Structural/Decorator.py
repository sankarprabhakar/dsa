# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 22:25:30 2024

@author: sanka
"""

## Decorate : 
# The Decorator Pattern is a structural design pattern that allows behavior
# to be added to individual objects dynamically, without affecting the
# behavior of other objects from the same class.

class Coffee:
    def cost(self):
        pass
    def description(self):
        pass

class SimpleCoffee(Coffee):
    def cost(self):
        return 5
    def description(self):
        return "This is simple Cofee"
    
class CoffeDecorator(Coffee):
    def __init__(self, coffee):
        self._coffee = coffee
    def cost(self):
        pass
    def description(self):
        pass
    
class Milk(CoffeDecorator):
    def cost(self):
        return self._coffee.cost() + 5
    def description(self):
        return self._coffee.description() + ' + Milk'

class Sugar(CoffeDecorator):
    def cost(self):
        return self._coffee.cost() + 1
    def description(self):
        return self._coffee.description() + ' + Sugar' 
    
class WippedCream(CoffeDecorator):
    def cost(self):
        return self._coffee.cost() + 5
    def description(self):
        return self._coffee.description() + ' + Cream'
    
if __name__ == "__main__":
    simple_coffee = SimpleCoffee()
    milk_coffee = Milk(simple_coffee)
    sugar_coffee = Sugar(simple_coffee)
    
    print(milk_coffee.description())
    print(sugar_coffee.description())
    print(Milk(Sugar(WippedCream(sugar_coffee))).description())
    
    
    
    
