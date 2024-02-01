# -*- coding: utf-8 -*-
"""
Created on Fri Feb  2 04:39:36 2024

@author: sanka
"""
from stack_deque import deque_stack

class prefix_postfix_evaluator:
    def __init__(self):
        return
    def postfix_evaluation(self, expression):
        expr = expression.split(" ");
        stack = deque_stack()
        for item in expr:
            if self.isoperator(item) == False:
                stack.push(item)
            else:
                op2 = stack.pop()
                op1 = stack.pop()
                result = self.operation(item, op1, op2)
                stack.push(result)
        return stack.pop()
    
    def prefix_evaluation(self, expression):
        expr = expression.split(" ");
        stack = deque_stack()
        for item in expr[::-1]: # read the expr from end of string
            if self.isoperator(item) == False:
                stack.push(item)
            else:
                op1 = stack.pop()
                op2 = stack.pop()
                result = self.operation(item, op1, op2)
                stack.push(result)
        return stack.pop()
                
        
        
    def isoperator(self, char):
        if char in ["+", "-", "*", "/"]:
            return True
        else:
            return  False

    def operation(self, operator,  op1, op2):
        #print(f" parameters are {operator} , {op1} , {op2}")
        expression =  str(op1) + operator + str(op2)
        result = eval(expression)
        return result
        
    
if __name__ == "__main__":
    evaluator = prefix_postfix_evaluator()
    result = evaluator.postfix_evaluation("5 6 +")
    print(result)
    result = evaluator.postfix_evaluation("5 6 7 + *")
    print(result)
    result = evaluator.postfix_evaluation("2 3 * 5 4 * + 9 -")
    print(result)
    result = evaluator.prefix_evaluation("+ 5 6")
    print(result)
    result = evaluator.prefix_evaluation("- + * 2 3 * 5 4 9")
    print(result)