# -*- coding: utf-8 -*-
"""
Created on Sat Feb 10 18:09:06 2024

@author: sanka
"""

## Coposite : Objects can be arranged in tree like structure
## Music playlist containing sub playlists.

class FilesystemComponent:
    def __init__(self, name):
        self.name = name
    def display(self,indent=0):
        pass
class File(FilesystemComponent):
    def display(self, indent=0):
        print(" " * indent + self.name)

class Folder(FilesystemComponent):
    def __init__(self,name):
        super().__init__(name)
        self.dir_struct = []
    def add(self, fileobj):
        self.dir_struct.append(fileobj)
   
        
    def display(self, indent=0):
        print(" " * indent + self.name)
        for item in self.dir_struct:
            item.display(indent+2)
        
if __name__ == "__main__":
    root = Folder("root")
    root_file_1 = File("File 1")
    root_file_2 = File("File 2")
    root_folder_1 = Folder("Root sub folder 1")
    root_folder_file1 = File("Sub 1 file 1")
    root_folder_file2 = File("Sub 1 file 2")   
    
    root.add(root_file_1)
    root.add(root_file_2)
    root.add(root_folder_1)
    root_folder_1.add(root_folder_file1)
    root_folder_1.add(root_folder_file2)
    
    root.display(0)