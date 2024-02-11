# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 11:20:30 2024

@author: sanka
"""

#Starategy pattern
# 1. Choosing different payment method in online store
# 2. chosing idfferent route on a map

# The Strategy pattern is a behavioral design pattern that defines a family
# of algorithms, encapsulates each one of them, and makes them 
# interchangeable. It allows a client to choose the algorithm to be
# used dynamically at runtime without modifying the client code.

######################### STRATEGIES #############################
class PaymentStrategy:
    def pay(self, amount):
        pass
class CreditCardPayment(PaymentStrategy):
    def __init__(self, card_no, expiry, cvv):
        self.card_no = card_no
        self.expiry = expiry
        self.cvv = cvv
    def pay(self, amount):
        print(f"Amount of  {amount} debited from Credit card {self.card_no}")
class PayPalPayment(PaymentStrategy):
    def __init__(self, email, password):
        self.email = email
        self.password = password
    def pay(self, amount):
        print(f"Amount of  {amount} debited from paypal {self.email}")
        
## Context ####################################################
class ShoppingCart:
    def __init__(self,payment_strategy):
        self.items = []
        self.payment_strategy = payment_strategy
    def add_item(self,item):
        self.items.append(item)
    def total_sum(self):
        return sum(item['price'] for item in self.items)
    def checkout(self):
        print("Checking out !!")
        self.payment_strategy.pay(self.total_sum())
        self.items = []
    def set_payment_strategry(self,payment_strategy):
        self.payment_strategy = payment_strategy
#############################################################

if __name__ == "__main__":
    sc = ShoppingCart(CreditCardPayment("123", "4/5", "89"))
    sc.add_item({"name": "biscuit", "price":20})
    sc.add_item({"name": "Tooth Brush", "price":30})
    sc.checkout()
    sc.set_payment_strategry(PayPalPayment("s@s.com", "123sdfasd"))
    sc.add_item({"name": "biscuit", "price":20})
    sc.add_item({"name": "Tooth Brush", "price":30})
    sc.checkout()
    
    


