def swapfirstlast():
    data=[1,2,3,4]
    data[0],data[-1] = data[-1],data[0]
    print(data)

if __name__ == "__main__":
    swapfirstlast()
    