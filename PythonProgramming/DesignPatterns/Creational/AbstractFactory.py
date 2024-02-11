# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 15:34:34 2024

@author: sanka
"""

## Abstract Factory : For each type of object we will a concrete factory will 
# makes the object. 

class Animal:
    def __init__(self):
        pass
    def sound(self):
        pass

class Dog(Animal):
    def sound(self):
        print("Woof!")
class Cat(Animal):
    def sound(self):
        print("Meow!")
        
class AnimalFactory:
    def createAnimal():
        pass
class DogFactory(AnimalFactory):
    def createAnimal(self):
        return Dog()
class CatFactory(AnimalFactory):
    def createAnimal(self):
        return Cat()



if __name__ == "__main__":
    dogFactory = DogFactory()
    catFactory = CatFactory()
    
    dog = dogFactory.createAnimal()
    cat = catFactory.createAnimal()

    dog.sound()
    cat.sound()    
    
    