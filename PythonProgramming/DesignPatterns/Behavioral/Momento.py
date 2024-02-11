# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 10:53:47 2024

@author: sanka
"""

# Momento
# Desing pattern to save state 

#The Memento pattern is a behavioral design pattern that allows the 
# capture and externalization of an object's internal state so that
# the object can be restored to this state later. It's commonly used
# to implement undo mechanisms or to provide checkpoints in an application.

# Saving the game in progress
# Auto save of documents
# Bookmarking pages in web browser

class Editor:
    def __init__(self):
        self.content = ""
    def write(self, text):
        self.content += text
    def get_content(self):
        return self.content
    def create_snapshot(self):
        return EditorSnapshot(self.content)
    def restore_snapshot(self, content):
        self.content = content
## Momento class
class EditorSnapshot:
    def __init__(self,content):
        self.content = content
    def get_snapshot(self):
        return self.content
    
## History mainteinter class
class History:
    def __init__(self):
        self.history = []
    def save_snapshot(self,editsnapshot):
        self.history.append(editsnapshot)
    def get_lastsnapshot(self):
        if len(self.history):
            return self.history.pop()


if __name__ == "__main__":
    editor = Editor() 
    history = History()

    editor.write("Hello ")
    history.save_snapshot(editor.create_snapshot()) 
    editor.write("World !!")
    history.save_snapshot(editor.create_snapshot()) 
    print(editor.get_content())
    editor.restore_snapshot(history.get_lastsnapshot().get_snapshot())    
    print(editor.get_content())
    editor.restore_snapshot(history.get_lastsnapshot().get_snapshot())    
    print(editor.get_content())
    #editor.restore_snapshot(history.get_lastsnapshot().get_snapshot())    
    #print(editor.get_content())
    