# -*- coding: utf-8 -*-
"""
Created on Fri Feb  2 05:11:54 2024

@author: sanka
"""
from stack_deque import deque_stack

class Infix_Postfix_converter:
    def __init__(self):
        self.operator_precedence = {"+":1, "-":1, "*":2,"\\":2, ")":3, "(":3}
        self.closing_paranthesis = [")", "}", "]"]
        self.opening_paranthesis = ["(","{","["]
        self.matching_paranthesis = {"(":")","{":"}","[":"]"}
    def infix_to_postfix(self, expression):
        output = ""
        expr = expression.split(" ")
        stack = deque_stack()
        #print(stack.peep())
        for item in expr:
            if self.isoperator(item) == True:
                ## if item is higher precidence or stack is empty place it
                if stack.isStackEmpty():
                    stack.push(item)
                else:
                    ## check precidence - you cannot place lower precedence over 
                    # higher precedence in stack.. pop all
                    if self.isPrecedenceHigher(stack.peep(),item) == False \
                    or  self.isClosingParanthesis(item) == True:
                        #item == ")":
                        while stack.isStackEmpty() != True:
                            if self.isMatchingOpeningParanthesis(stack.peep(),item) == False:
                                output += stack.pop() + " "
                            else:
                                stack.pop()
                                break
                    stack.push(item)
                        
            else:
                output = output + item + " "
            
        while stack.isStackEmpty() != True:
            output = output +  stack.pop() + " "
        return output
    
    def isMatchingOpeningParanthesis(self, peeped_op, op):
        if peeped_op in self.opening_paranthesis and\
            peeped_op == self.matching_paranthesis[op]:
                return True
        else:
            return False
            
                    
    def isClosingParanthesis(self, operator):
        if operator in self.closing_paranthesis:
            return True
        else:
            return False
    def isPrecedenceHigher(self, operator1, operator2):
        if self.operator_precedence[operator1] >= self.operator_precedence[operator2]:
            return True
        else:
            return False
        
    
    def isoperator(self, char):
        if char in ["+", "-", "*", "/", "(", ")"]:
            return True
        else:
            return  False


if __name__ == "__main__":
    t = Infix_Postfix_converter()
    result = t.infix_to_postfix("a + b * c - d * e")
    print(result)