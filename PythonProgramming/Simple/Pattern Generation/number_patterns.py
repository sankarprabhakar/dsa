if __name__ == "__main__":
    n = int(input("Enter level"))
    for i in range(1,n+1):
        for j in range(i):
            print(i, end=" ")
        print("\n")
    
    for i in range(1,n+1):
        for j in range(1,i+1):
            print(j,end =" ")
        print("\n")
    
    for i in range(5,0,-1):
        for j in range(i):
            print(i, end= " ")
        print("\n")
