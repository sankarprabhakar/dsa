# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 15:54:16 2024

@author: sanka
"""

## Builder : A class is used to create complex object - Which may involve 
# creation of other object or invokation of other methods to complete 
# the operation.


######################## MEAL ITEMS ~##############################
class Item:
    def __init__(self, name, packing, price):
        self.name = name
        self.packing = packing
        self.price= price
    def __str__(self):
        return  f"{self.name}  {self.packing}   {self.price}"
class vegBurger(Item):
    def __init__(self):
         super().__init__("VegBurger", "Wrap", 10)

class chickenBurger(Item):
    def __init__(self):
        super().__init__("ChickenBurger", "Box", 20)
class coke(Item):
    def __init__(self):
        super().__init__("Coke", "Bottle", 5)
class pepsi(Item):
    def __init__(self):
        super().__init__("Pepsi", "Bottle", 5)
############################### MEAL CLASS ##########################################
class Meal:
    def __init__(self):
        self.items = []
    def addItem(self,item):
        self.items.append(item)
    def __str__(self):
        details = ""
        for item in self.items:
            details += "\n" +  item.__str__()
        return details

############################# Builder CLASS ###############################
class mealBuilder:
    def __init__(self):
        pass
    def prepare_veg_meal(self):
        pass
    def prepare_nonveg_meal(self):
        pass

class vegMealBuilder(mealBuilder):
    def prepare_veg_meal(self):
        meal = Meal()
        meal.addItem(vegBurger())
        meal.addItem(coke())
        return meal

class nonVegMealBuilder(mealBuilder):
    def prepare_nonveg_meal(self):
        meal = Meal()
        meal.addItem(chickenBurger())
        meal.addItem(pepsi())
        return meal

############################### Director Class #############################

class Waiter:
    def __init__(self):
        self.builder = None
    def set_builder(self,builder):
        self.builder = builder
    def get_veg_meal(self):
        return self.builder.prepare_veg_meal()
    def get_non_veg_meal(self):
        return self.builder.prepare_nonveg_meal()
    
#########################################################


if __name__ == "__main__":
    
    vegmealbuilder = vegMealBuilder()
    nonvegmealbuilder = nonVegMealBuilder()
    
    waiter = Waiter()
    waiter.set_builder(vegMealBuilder())
    mymeal = waiter.get_veg_meal()
    print(mymeal)
    
    
    waiter.set_builder(nonVegMealBuilder())
    mymeal = waiter.get_non_veg_meal()
    print(mymeal)
    
    
    
    
    