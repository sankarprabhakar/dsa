# -*- coding: utf-8 -*-
"""
Created on Tue Jan 30 05:05:10 2024

@author: sanka
"""

from stack_deque import deque_stack

# Checking balanced parathesis in expression
# 1. Scan the expression from left to right and Push the opening braces to stack
# 2. When closing brances is finished pop from stack and check if it is a matching
#    opening braces
# 3. If not check if it is . Expression is not balanced
# 4. End of expression scanning, check if stack is empty or not. if not empty 
#    it is unbalanced.

class Paranthesis_Balancing:
    def __init__(self):
        self.stack = deque_stack()
        self.opening = ["{","[","(","<"]
        self.closing = ["]","}",")",">"]
        self.matching = {"}":"{","]":"[",")":"(",">":"<"}
        return
    def check_paranthesis(self, expr):
        #print(expr)
        for char in expr:
            #print(char)
            if self.isOpeningBrace(char):
                self.stack.push(char)
                continue
            if self.isClosingBrace(char):
                
                if self.stack.isStackEmpty() == True or\
                    self.isMatchingBraces(char,self.stack.peep()) == False:
                    return False
                else:
                   # print("Poping")
                    self.stack.pop()
        #print(self.stack.isStackEmpty())
        
        if self.stack.isStackEmpty() == True:
            return True
        else:
            return False
    
    def isOpeningBrace(self,char):
        if char in self.opening:
            return True
        else: 
            return  False

    def isClosingBrace(self,char):
        if char in self.closing:
            return True
        else: 
            return  False
        
    def isMatchingBraces(self,closing, opening):
        if opening == self.matching[closing]:
            return True
        else:
            return False

if __name__ == "__main__":
    p = Paranthesis_Balancing()
    #print(p.check_paranthesis('{Sankar}'))
    assert p.check_paranthesis('{Sankar}') == True, "True Expected"
    assert p.check_paranthesis('{Sankar})') == False, "False Expected"
    
    
