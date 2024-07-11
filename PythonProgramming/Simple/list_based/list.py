def swapfirstlast():
    data=[1,2,3,4]
    data[0],data[-1] = data[-1],data[0]
    print(data)

def swap_two_position(list,pos1, pos2):
    list[pos1],list[pos2] = list[pos2],list[pos1] 
    return list
if __name__ == "__main__":
    swapfirstlast()
    print(swap_two_position([1,2,3,4,5],0,1))