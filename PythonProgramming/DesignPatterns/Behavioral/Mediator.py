# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 07:44:00 2024

@author: sanka
"""

## Mediator
# Social media platform : Connecting users
# Teacher : Connection students
# Customer service center: connecting customer to service agents.
# Chatroom : chat room is meidator for two or more users

class Mediator:
    def notify(self, sender, receiver, event):
        pass

class ChatRoom(Mediator):
    _instance = None
    initialized = False
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance
    def __init__(self):
        if(self.initialized): return
        self.initialized = True
        self.users = {}
        #print("init called ")
    def add_user(self, username, userobject):
        self.users[username] = userobject
        #print(self.users)
    def notify(self, from_user, to_user, event):
        #print(self.users)
        if to_user in self.users:
            self.users[to_user].receive(from_user,to_user, event)

class Collegues:
    def __init__(self,name,mediator):
        self.mediator = mediator
        self.name = name
        self.mediator.add_user(name, self)
    def send(self, to_user ,message):
        self.mediator.notify(self.get_username(), to_user, message)
    def get_username(self):
        return self.name
    def receive(self,from_user,to_user, message):
        print(f"{from_user} -> to {to_user} : {message}")

class User(Collegues):
    def __init__(self, name):
        super().__init__(name, ChatRoom())
        #print("number of users")
    def send(self, to_user, message):
        #print(f"{to_user}: {message}")
        super().send(to_user, message)

if __name__ == "__main__":
    user1 = User("Sankar")
    user2 = User("Sankar 2")
    #user1.add_
    
    user2.send("Sankar", "Hello")
    user2.send("Sankar 2", "Hello")
    user1.send("Sankar 2", "Whats up ?")
    
        
        
        
        
    
