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
                print(f"\noperator is {item}", end = "\n")
                ## if item is higher precidence or stack is empty place it
                if stack.isStackEmpty() or self.isOpeningParanthesis(item):
                    stack.push(item)
                elif self.isClosingParanthesis(item) == True:
                    while self.isMatchingOpeningParanthesis(stack.peep(), item) == False:
                        #poped_element = stack.pop()
                        output += stack.pop() + " "
                    stack.pop() ##pop the clsing brace
                elif self.isPrecedenceHigher(stack.peep(), item) == True:
                    while stack.isStackEmpty() == False:
                        #poped_element = stack.pop()
                        if self.isOpeningParanthesis(stack.peep()) == False:
                            output += stack.pop() + " "
                        else:
                            break
                    stack.push(item)
                else:
                    stack.push(item)
            else:
                output = output + item + " "
        #poped_element = ""
        while stack.isStackEmpty() != True:
            poped_element = stack.pop()
            if self.isClosingParanthesis(poped_element) == False:
                output = output +  poped_element + " "
        return output
    
    def isMatchingOpeningParanthesis(self, peeped_op, op):
        if peeped_op in self.opening_paranthesis:
            if op == self.matching_paranthesis[peeped_op]:
                return True
        return False
            
    def isOpeningParanthesis(self,operator):
        if operator in self.opening_paranthesis:
            return True
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
    result = t.infix_to_postfix("( a + b ) * ( c - d ) * e")
    print(result)