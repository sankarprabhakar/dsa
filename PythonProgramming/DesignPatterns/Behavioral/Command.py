# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 05:58:54 2024

@author: sanka
"""

## Command Pattern
# List of chores to Robot, it does in rder
# Scheduling a task on computer
# Creating a to-do list app

# The Command pattern is a behavioral design pattern that encapsulates a
# request as an object, thereby allowing for parameterization of clients
# with queues, requests, and operations. It enables the parameterization 
# of objects with operations and supports undoable operations.

# Command is a behavioral design pattern that turns a request into a 
# stand-alone object that contains all information about the request.
# This transformation lets you pass requests as a method arguments, delay 
# or queue a request’s execution, and support undoable operations.

class Command:
    def execute(self):
        pass
    def undo(self):
        pass
#Concrete command
class InsertCommand(Command):
    def __init__(self,text_document, text_to_insert, insert_position):
        self.doc = text_document
        self.txt_to_insert = text_to_insert
        self.insert_position = insert_position
        self._text_added_in_last_op  = None
    def execute(self):
        self._text_added_in_last_op = self.doc.insert(self.txt_to_insert, self.insert_position)
    def undo(self):
        if self._text_added_in_last_op:
            self.doc.delete(len(self.text_to_insert), self.insert_position)
#Concrete command
class DeleteCommand(Command):
    def __init__(self, text_document,length,position):
        self.doc = text_document
        self.length = length
        self.position = position
        self._text_removed_in_last_op = None
    def execute(self):
        self._text_removed_in_last_op = self.doc.delete(self.length, self.position)
    def undo(self):
        if self._text_removed_in_last_op:
            self.doc.insert(self._text_removed_in_last_op,self.position)
# Receiver: TextDocument
class TextDocument:
    def __init__(self):
        self.content = ""
    def insert(self, txt, position):
        self.content = self.content[:position] + txt + self.content[position:]
        return self.content
    def delete(self, length, position):
        delete_content = self.content[position: position+length]
        self.content = self.content[:position] + self.content[(position+length):]
        return delete_content
    def get_content(self):
        return self.content
#invoker of command
class TextEditor:
    def __init__(self):
        self.history = []
    def execute_command(self, command):
        self.history.append(command)
        command.execute()
    def undo_command(self):
        if self._history:
            command = self.history.pop()
            command.execute()

if __name__ == "__main__":
    document = TextDocument()
    insert_command = InsertCommand(document, "Hello World", 0)
    editor = TextEditor()
    editor.execute_command(insert_command)
    print(document.get_content())
    
    
    delete_command = DeleteCommand(document, 3, 6)
    editor.execute_command(delete_command)
    print(document.get_content())