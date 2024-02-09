# -*- coding: utf-8 -*-
"""
Created on Fri Feb  9 04:47:33 2024

@author: sanka
"""

class Mergesort:
    def __init__(self):
        return
    def sort(self, array,order = "asc"):
        ## divide the array into two
        ## call sort self and right
        ## merge the elements into the input array 
        ## if number of element is one or lesser return
        
        arr_len = len(array)
        if arr_len <= 1:
            return array
        l_sorted = self.sort(array[:arr_len // 2],order)
        r_sorted = self.sort(array[arr_len//2:], order)
        #llen = rlen = -1
        #if type(l_sorted) == list:
        llen = len(l_sorted)
        #if type(r_sorted) == list:
        rlen = len(r_sorted)
        
        #llen = -1 if llen == 0 else llen
        #rlen = -1 if rlen == 0 else rlen
        
        i = 0
        j = 0
        k = 0
        #print(l_sorted)
        #print(r_sorted)
        ## merge into l_sorted & r_sorted in to array.
        #for i in range(arr_len):
        if order == 'asc': ## Ascending order
            while j>=0 and k>=0  and j < llen and k < rlen:
                #print(j,llen,k,rlen)
                
                if l_sorted[j] < r_sorted[k]:
                    array[i] = l_sorted[j]
                    j += 1
                    i += 1
                else:
                    array[i] = r_sorted[k]
                    k += 1
                    i += 1
            while j  <  llen:
                array[i] = l_sorted[j]
                j += 1
                i += 1
            while k < rlen:
                array[i] = r_sorted[k]
                k += 1
                i += 1
        else: # Logic for descending
            while j>=0 and k>=0  and j < llen and k < rlen:
                #print(j,llen,k,rlen)
                
                if l_sorted[j] > r_sorted[k]:
                    array[i] = l_sorted[j]
                    j += 1
                    i += 1
                else:
                    array[i] = r_sorted[k]
                    k += 1
                    i += 1
            while j  <  llen:
                array[i] = l_sorted[j]
                j += 1
                i += 1
            while k < rlen:
                array[i] = r_sorted[k]
                k += 1
                i += 1
                
        #print(array)
        return array
            
if __name__ == "__main__":
    mergesort = Mergesort()
    print(mergesort.sort([9,8,7,2,5,4,99], order = "asc"))
    print(mergesort.sort([9,8,7,55,5,4], order = "dsc"))
    print(mergesort.sort([9], order = "dsc"))
    print(mergesort.sort([9,10], order = "dsc"))          
                
            
    
        
        
        