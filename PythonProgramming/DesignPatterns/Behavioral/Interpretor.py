# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 06:55:52 2024

@author: sanka
"""

# The Interpreter pattern is a behavioral design pattern that is used to
#  define a grammar for a language and provide an interpreter to interpret
# sentences in that language. It allows you to evaluate sentences in a
# language by representing them as abstract syntax trees, 
# which are then interpreted by the interpreter.
class context:
    def __init__(self):
        self.variables = {}
    def set_variable(self, name, value):
        self.variables[name] = value
    def get_variable(self, name):
        return self.variables[name]

#########################################################################
class Expression:
    def interpret(self,context):
        pass
class Variable(Expression):
    def __init__(self,name):
        self.name= name
    def interpret(self, context):
        return context.get_variable(self.name)
class AND(Expression):
    def __init__(self,left,right):
        self.left = left
        self.right = right
    def interpret(self, context):
        return self.left.interpret(context) and self.right.interpret(context)

class OR(Expression):
    def __init__(self,left,right):
        self.left = left
        self.right = right
    def interpret(self, context):
        return self.left.interpret(context) or self.right.interpret(context)

class NOT(Expression):
    def __init__(self,expression):
        self.expression = expression
       
    def interpret(self, context):
        return not self.expression.interpret(context)
###########################################################################
if __name__ == "__main__":
    cxt = context()
    cxt.set_variable("a", True)
    cxt.set_variable("b", True) 
    cxt.set_variable("c", True)
    
    expr = AND(AND (Variable("a"), Variable("b")), NOT(Variable("c")))
    print(expr.interpret(cxt))
    
    