# -*- coding: utf-8 -*-
"""
Created on Fri Feb  2 05:11:54 2024

@author: sanka
"""
from stack_deque import deque_stack

class Infix_Postfix_converter:
    def __init__(self):
        self.operator_precedence = {"+":1, "-":1, "*":2,"\\":2}
    def infix_to_postfix(self, expression):
        output = ""
        expr = expression.split(" ")
        stack = deque_stack()
        for item in expr:
            if self.isoperator(item) == True:
                ## if item is higher precidence or stack is empty place it
                if stack.isStackEmpty():
                    stack.push(item)
                else:
                    ## check precidence - you cannot place lower precedence over 
                    # higher precedence in stack.. pop all
                    if self.isPrecedenceHigher(stack.peep(),item) == False:
                        while stack.isStackEmpty() != True:
                            output += stack.pop() + " "
                    stack.push(item)
                        
            else:
                output = output + item + " "
            
        while stack.isStackEmpty() != True:
            output = output +  stack.pop() + " "
        return output
                    
                
    def isPrecedenceHigher(self, operator1, operator2):
        if self.operator_precedence[operator2] >= self.operator_precedence[operator1]:
            return True
        else:
            return False
        
    
    def isoperator(self, char):
        if char in ["+", "-", "*", "/"]:
            return True
        else:
            return  False


if __name__ == "__main__":
    t = Infix_Postfix_converter()
    result = t.infix_to_postfix("a + b * c - d * e")
    print(result)