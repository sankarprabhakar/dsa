# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 05:45:30 2024

@author: sanka
"""

class HandleApproval:
    def __init__(self, successor):
        self.sucessor = successor
    def handle_request(self,amount):
        pass
class GeneralManager(HandleApproval):
    def __init__(self):
        super().__init__(None)
    def handle_request(self,amount):
        if amount >0 and amount < 1000:
            print("GeneralManager approved")
        else:
            print("Rejected as the amount is more than limit of GM")

class SeniorSupervisor(HandleApproval):
    def __init__(self):
        super().__init__(GeneralManager())
    def handle_request(self,amount):
        if amount >100 and amount < 500:
            print("SeniorSupervisor approved")
        else:
            print(f"{amount} is above SeniorSuperVisor limit Rerouting for GM")
            self.sucessor.handle_request(amount)

class Supervisor(HandleApproval):
    def __init__(self):
        super().__init__(SeniorSupervisor())
    def handle_request(self,amount):
        if amount >0 and amount < 100:
            print("Supervisor approved")
        else:
            print(f"{amount} is above SuperVisor limit Rerouting for SeniorSupervisor")
            self.sucessor.handle_request(amount)            

if __name__ == "__main__":
    manager = Supervisor()
    manager.handle_request(50)
    manager.handle_request(150)
    manager.handle_request(550)
    
        