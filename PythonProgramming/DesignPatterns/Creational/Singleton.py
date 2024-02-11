# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 15:01:52 2024

@author: sanka
"""

## When only one instance of class is required
# TV remote controle
# Printer at office
# SQL server connection..

class Singleton:
    _instance = None
    def __new__(cls):
        if cls._instance == None:
            cls._instance = super().__new__(cls)
        return cls._instance
    

if __name__ == "__main__":
    s1 = Singleton()
    s2 = Singleton()
    if s1 is s2:
        print(f"{id(s1)} and {id(s2)} is same - Only one obhject is created")