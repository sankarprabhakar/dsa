# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 12:13:00 2024

@author: sanka
"""

## Observer pattern

# Geeting notifcation from applciaton 
# Receiving allerts on emergencey news
# Weather updates in weather app

# The Observer pattern is a behavioral design pattern where an object,
# known as the subject, maintains a list of its dependents, called observers,
# and notifies them of any changes in state, usually by calling one of 
# their methods. This pattern is used to establish a one-to-many dependency 
# between objects, so that when one object changes state, all its dependents are notified and updated automatically.

class Observer:
    def update(self, message):
        pass
class Subject:
    def __init__(self):
        self.observers = []
    def add_observer(self,observer):
        self.observers.append(observer)
    def remove_observer(self, observer):
        self.observers.remove(observer)
    def notify_observer(self, temperature):
        for observer in self.observers:
            observer.update(temperature)

###################################################
class Display(Observer):
    def __init__(self, name):
        self.name = name
    def update(self,temperature):
        print(f"{self.name} display : Temperature is {temperature}")
class Emailer(Observer):
    def __init__(self, name):
        self.name = name
    def update(self,temperature):
        print(f"{self.name} Emails : Temperature is {temperature}")
################################################################

class WeatherStation(Subject):
    def __init__(self):
        super().__init__()
        self.temperature = 0
    def set_temperature(self, temp):
        self.temperature = temp
        self.notify_observer(temp)
    def temperature(self):
        return self.temperature
##################################################################
if __name__ == "__main__":
    weatherstation = WeatherStation()
    display = Display("Display 1")
    emailer = Emailer("Emailer 1")
    weatherstation.add_observer(display)
    weatherstation.add_observer(emailer)
    weatherstation.set_temperature(55)
    

        

