import math
if __name__ == "__main__":
    n = int(input())
    for i in range(1,n+1):
        print("*" * i)
    ## right aligned 
    for i in range(1,n+1):
        print(" " * (n-i), end="")
        print("*" * i, end="\n")
    ## piramid
    for i in range(0,n):
        stars = 2*i + 1
        spaces =  n - i
        print(" " * spaces, end ="")
        print("*" * stars, end="\n")
    ## Diamond
    for i in range(0,math.floor(n/2)+1):
        stars = 2*i + 1
        spaces =  n - i
        print(" " * spaces, end ="")
        print("*" * stars, end="\n")
    for i in range(math.ceil(n/2),-1,-1):
        stars = 2*i + 1
        spaces =  n - i
        print(" " * spaces, end ="")
        print("*" * stars, end="\n")