# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 11:39:44 2024

@author: sanka
"""

# Template pattern
# Following a receipe but ingredients are different
# Making differnt type of sandwiches
# Creating different document with same format

# The Template Method pattern is a behavioral design pattern that defines 
# the skeleton of an algorithm in the superclass but lets subclasses 
# override specific steps of the algorithm without changing its structure.
# It allows subclasses to provide specific implementations for certain steps
# of the algorithm while keeping the overall algorithm intact.

class ReportGenerator:
    def __init__(self):
        pass
    def generate_report(self):
        self.generate_header()
        self.generate_body()
        self.generate_footer()
    def generate_header(self):
        pass
    def generate_body(self):
        pass
    def generate_footer(self):
        pass

class PDFReportGenerator(ReportGenerator):
    def generate_header(self):
        print("PDF report header")
    def generate_body(self):
        print("PDF report Body")
    def generate_footer(self):
        print("PDF report footer")

class HTMLReportGenerator(ReportGenerator):
    def generate_header(self):
        print("HTML report header")
    def generate_body(self):
        print("HTML report Body")
    def generate_footer(self):
        print("HTML report footer")

if __name__ == "__main__":
    pdf = PDFReportGenerator()
    pdf.generate_report()
    html = HTMLReportGenerator() 
    html.generate_report()       