# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 17:44:24 2024

@author: sanka
"""

# Bridge pattern --> The Bridge Pattern is a structural design pattern 
# that decouples an abstraction from its implementation, allowing the two
# to vary independently.

class Shape:
    def __init__(self,drawing_api):
        self.drawing_api = drawing_api
    def draw(self):
        pass
class Circle(Shape):
    def __init__(self,x,y,radius,drawing_api):
        super().__init__(drawing_api)
        self.x = x
        self.y = y
        self.radius = radius
    def draw(self):
        self.drawing_api.draw_circle(self.x,self.y,self.radius)
class Square(Shape):
    def __init__(self,x,y,side_length,drawing_api):
        super().__init__(drawing_api)
        self.x = x
        self.y = y
        self.side = side_length
    def draw(self):
        self.drawing_api.draw_square(self.x,self.y,self.side)

class DrawingAPI:
    def draw_circle(self, x,y,radius):
        pass
    def draw_square(self, x,y,side):
        pass

class DrawingAPI1(DrawingAPI):
    def draw_circle(self, x,y,radius):
        print(f"Drawing Cicle with x {x} y {y} radius {radius}")
        
    def draw_square(self,x,y,side):
        print(f"Drawing Square with x {x} y {y} side {side}")


if __name__ == "__main__":
    circle = Circle(5, 6, 10, DrawingAPI1())
    sqr    = Square(5 , 5, 110, DrawingAPI1())
    
    print(circle.draw())
    print(sqr.draw())