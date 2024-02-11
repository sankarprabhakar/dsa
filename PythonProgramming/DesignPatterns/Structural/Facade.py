# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 04:40:07 2024

@author: sanka
"""

## Facade : Desing pattern where we wanted a simple interface for complex
# internal operations

# The Facade design pattern is a structural pattern that provides a
# simplified interface to a complex system of classes, interfaces, 
#or subsystem
class CPU:
    def __init__(self):
        pass
    def Freeze(self):
        print(f"CPU Freezing")
    def Jump(self, position):
        print(f"CPU is  jumping to {position}")
    def Executing(self):
        print(f"Executing")

class RAM:
    def load(self,position,data):
        print(f"HDD loading data {data} at {position}")

class HDD:
    def read(self,lba,size):
        print(f"HDD is reading {size} bytes from {lba}")

class ComputerFacade:
    def __init__(self):
        self.cpu = CPU()
        self.RAM = RAM()
        self.HDD = HDD()
    def start(self):
        self.cpu.Freeze()
        self.RAM.load(0x00, "Boot loader")
        self.cpu.Jump(0x00)
        self.cpu.Executing()
        self.HDD.read(0x456, 1024)
        
if __name__ == "__main__":
    computerfacade = ComputerFacade()
    computerfacade.start()
        