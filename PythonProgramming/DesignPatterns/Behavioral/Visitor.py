# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 11:52:07 2024

@author: sanka
"""

#Visitor pattern
# Teacher checking each students home work
# A doc visiting all the patient rools
# Technician checking differnt machines in the factory.

# The Visitor pattern is a behavioral design pattern that allows adding 
# new operations to existing classes without modifying their structure.
# It separates the algorithm from the object structure, making it easier
# to add new operations or algorithms that work on the elements of an 
# object structure.

class Shape:
    def accept(self,visitor):
        pass

class Square(Shape):
    def __init__(self,side):
        self.side = side
    def accept(self, visitor):
        return visitor.visit(self)
class Circle(Shape):
    def __init__(self,radius):
        self.radius = radius
    def accept(self, visitor):
       # print("Cicle accpet")
        return visitor.visit(self)

## After this impl, there is a request to modify above classes to get the area
# and perimeter. how to we do it.. Create visitors and get eh work done, instead
# of modifying the operator.

class Visitor:
    def visit(self,obj):
        pass
class CircleArea(Visitor):
    def visit(self, circleObj):
        #print("Visit")
        return  3.14 * circleObj.radius ** 2 # pi * r ** 2
class CirclePermeter(Visitor):
    def visit(self, circleObj):
        return  3.14 * circleObj.radius * 2 # pi * r * 2
class SquareArea(Visitor):
    def visit(self, square):
        return   square.side  ** 2 # side ** 2
class SquarePermeter(Visitor):
    def visit(self, square):
        return  4 * square.side

#####################################################################

if __name__ == "__main__":
    circle = Circle(5)
    square = Square(5)
    circle_area = CircleArea()
    circlperi = CirclePermeter()
    squarearea = SquareArea()
    squareperi = SquarePermeter()
    
    print(circle.accept(circle_area))
    print(circle.accept(circlperi))
    print(square.accept(squarearea))
    print(square.accept(squareperi))
    
    
    
    
    