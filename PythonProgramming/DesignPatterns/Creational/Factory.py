# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 15:06:41 2024

@author: sanka
"""
# Factory class can make differnt type of other objects based on the input type of 
# object requested to create. Eg. Factory creates differnt types of toys. 
# Creating different types of 

class Animal:
    def __init__(self):
        pass
    def sound(self):
        pass

class Cat(Animal):
    def __init__(self):
        pass
    def sound(self):
        print("Meow!!\n")

class Dog(Animal):
    def __init__(self):
        pass
    def sound(self):
        print("Woof!!\n")
        
        
class AnimalFactory:
    def __init__(self):
        pass
    def createAnimal(self,animal_type):
        if animal_type == "Dog":
            return Dog()
        elif animal_type == "Cat":
            return Cat()
        

if __name__ == "__main__":
    animalFactory = AnimalFactory()
    dog = animalFactory.createAnimal("Dog")
    cat = animalFactory.createAnimal("Cat")
    dog.sound()
    cat.sound()
    