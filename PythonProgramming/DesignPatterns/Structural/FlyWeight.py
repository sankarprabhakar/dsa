# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 05:08:36 2024

@author: sanka
"""

# The Flyweight design pattern is a structural pattern that aims to
# minimize memory usage or computational expenses by sharing as much as
# possible with similar objects. It achieves this by storing common state 
# that multiple objects share externally, and allowing objects to reference
# this shared state rather than replicating it internally.

#  Flyweight pattern could be a text editor where multiple instances of 
# characters are used. Instead of creating a new instance for each character,
# the Flyweight pattern can be applied to share common character objects
# and reduce memory consumption.

class Character:
    def __init__(self,char):
        self.char = char
    def display(self, font_size):
        print(f"Diplay {self.char} in font size {font_size}")
class CharacterFactory:
    _characters = {}
    def get_character(cls,char):
        if char not in cls._characters:
            cls._characters[char] = Character(char)
        return cls._characters[char]
class TextEditor:
    def __init__(self):
        self.characters = []
    def add_character(self,char,char_size):
        charobj = CharacterFactory.get_character(CharacterFactory,char)
        self.characters.append((charobj,char_size))
    def display(self):
        for char, size in self.characters:
            char.display(size)

if __name__ == "__main__":
    txtEditor = TextEditor()
    txtEditor.add_character("a", 10)
    txtEditor.add_character("a", 12)
    txtEditor.add_character("B", 10)
    txtEditor.add_character("C", 10)
    txtEditor.add_character("D", 10)
    txtEditor.add_character("E", 10)
    txtEditor.add_character("F", 10)
    txtEditor.add_character("G", 10)
    txtEditor.add_character("H", 10)
    
    txtEditor.display()
    
            
    