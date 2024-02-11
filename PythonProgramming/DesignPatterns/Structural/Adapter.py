# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 16:43:06 2024

@author: sanka
"""
## Structural pattern
## Abstract Pattern

############################# Sockets #########################
class EuropeanSocket:
    def eu_power_socket(self):
        print("Connected through European socket")

class JapaneseSocket:
    def jp_power_socket(self):
        print("Connected through Japanese socket")

############################ Adapter ####################################
class PowerAdapter:
    
    def __init__(self):
        self.power_socket = None
    def power(self):
        pass

class EuropeanAdapter(PowerAdapter):
    def __init__(self):
        self.power_socket = EuropeanSocket()
    def power(self):
        self.power_socket.eu_power_socket()

class JapaneseAdapter(PowerAdapter):
    def __init__(self):
       self.power_socket = JapaneseSocket()
    def power(self):
        self.power_socket.jp_power_socket()

################################## Coffe machine  ###############################

class CoffeeMachine:
    def __init__(self):
        self.powerAdapter = None
    def power_up(self):
        print("Coffe machine is ", end = " ")
        self.powerAdapter.power()
    def set_power_adapter(self,power_adap):
        self.powerAdapter = power_adap

###########################################################################


if __name__ == "__main__":
    coffee_machine = CoffeeMachine()
    coffee_machine.set_power_adapter(EuropeanAdapter())
    coffee_machine.power_up()
    
    coffee_machine.set_power_adapter(JapaneseAdapter())
    coffee_machine.power_up()
    
    
