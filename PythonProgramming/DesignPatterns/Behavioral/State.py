# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 11:08:21 2024

@author: sanka
"""

## State Pattern
## 


# Phone have different modes - play, sleep ,dance
# traffic light changing colores

# The State pattern is a behavioral design pattern that allows an object
# to change its behavior when its internal state changes. The pattern
# involves creating state objects that represent various states of 
#the object and a context object that maintains a reference to the 
#current state. The context object delegates the state-specific behavior
# to the current state object.

class State:
    def handler(self):
        pass
    
class State1(State):
    def handler(self):
        print("We are in state 1")

class State2(State):
    def handler(self):
        print("We are in state 2")
        
class Context:
    def __init__(self):
        self.state = None
    def set_state(self,state):
        self.state = state
    def request(self):
        if self.state != None:
            self.state.handler()
        else:
            print("No state handle set")
if __name__ == "__main__":
    ctxt = Context()
    ctxt.set_state(State1()) 
    ctxt.request()
    ctxt.set_state(State2())
    ctxt.request()