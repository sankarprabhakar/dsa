# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 12:30:03 2024

@author: sanka
"""

## MVP
# MVP stands for Model-View-Presenter, which is a design pattern used primarily
#in software engineering to separate the concerns of presentation logic from
# the UI components. It's particularly popular in GUI applications and web
# development.

#Here's a brief explanation of each component:

#Model: The Model represents the data and business logic of the application.
# It's responsible for managing data, state, and business rules. It notifies
# the Presenter of any changes in the data.

#View: The View is responsible for presenting the user interface and 
#capturing user input. It's passive and does not contain any application
# logic. It forwards user actions to the Presenter for processing and 
#updates its display based on the data received from the Presenter.

#Presenter: The Presenter acts as a mediator between the View and the Model. It
# contains the application logic and handles user inputs from the View. 
#It interacts with the Model to retrieve data and updates the View with 
#the results.

class UserModel:
    def __init__(self, username, password):
        self.username = username
        self.password = password
    def validate_credential(self):
        return self.username == "admin" and self.password == "password"

class LoginView:
    def display_login_view(self):
        print("Enter the username : ")
        username = input()
        print("Enter password")
        password = input()
        return username, password
    def display_result(self, success):
        if success:
            return "Login Sucess!!"
        else:
            return "Login failed!!"
class Presenter:
    def __init__(self,view,model):
        self.view = view
        self.model = model
    def handle_login(self):
        username,password = self.view.display_login_view()
        usermodel = UserModel(username, password)
        success = usermodel.validate_credential()
        return self.view.display_result(success)

if __name__ == "__main__":
    userModel = UserModel("","")
    view = LoginView()
    presenter = Presenter(view, userModel) 
    print(presenter.handle_login())    
        
    