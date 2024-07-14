def swapfirstlast():
    data=[1,2,3,4]
    data[0],data[-1] = data[-1],data[0]
    print(data)

def swap_two_position(list,pos1, pos2):
    list[pos1],list[pos2] = list[pos2],list[pos1] 
    return list

def getlen(list):
    length = sum(1 for _ in list)
    return length

def checkavailable(list, n):
    if n in list:
        return True
    else:
        return False
def clearlist():
    my_list = [1,2,3,4]
    print(my_list)
    my_list = []
    print(my_list)
    my_list = [1,2,3,4]
    del my_list[:]
    print(my_list)
    

if __name__ == "__main__":
    swapfirstlast()
    print(swap_two_position([1,2,3,4,5],0,1))
    print(getlen([1,2,3,4,5]))
    print(checkavailable([1,2,3,4,5],5))
    clearlist()