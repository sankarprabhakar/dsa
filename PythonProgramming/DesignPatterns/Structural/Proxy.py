# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 05:25:35 2024

@author: sanka
"""


# The Proxy design pattern is a structural pattern that provides a surrogate 
# or placeholder for another object to control access to it. 
# It allows you to create a representative object that controls 
# access to another object, which may be remote, expensive to create,
# or in need of securing.

class FileAccess:
    def request(self,file_name):
        pass
class RealFileAccess(FileAccess):
    def request(self,file_name):
        print(f"Accessing the file {file_name}")
class ProxyFileAccess(FileAccess):
    def __init__(self,real_file_access, user_permission):
        self.real_file_access = real_file_access
        self.user_permission = user_permission
    def request(self, file_name):
        if self.user_permission.get(file_name) == 'read':
            self.real_file_access.request(file_name)
        else:
            print(f"File access to {file_name} is restricted")

if __name__ == "__main__":
    real_file_access = RealFileAccess()
    user1_permission = {"File 1": "read", "File 3": "read"}
    user2_permission = {"File 2": "read", "File 4" : "read"}
    
    pxy1 = ProxyFileAccess(real_file_access, user1_permission)
    pxy2 = ProxyFileAccess(real_file_access, user2_permission)
    
    pxy1.request("File 1")
    pxy1.request("File 4")
    
    pxy2.request("File 2")
    pxy2.request("File 3")
    
    
    