if __name__ == "__main__":
    matrix = [[1,2,3],[4,5,6],[7,8,9]]

    ## navigate diagonal
    row = col = 0
    no_row = len(matrix)
    no_col = len(matrix[0])
    while row < no_row and col < no_col:
        before = row
        after = no_col - row - 1
        print("* " * before, end="")
        print(matrix[row][col], end=" ")
        print("* " * after,end = "\n")
        row +=1
        col+=1
    row = 0
    col = no_col-1
    while row < no_row and col < no_col:
        after = row
        before = no_col - row - 1
        print("* " * before, end="")
        print(matrix[row][col], end=" ")
        print("* " * after,end = "\n")
        row +=1
        col-=1
    # j+ i+ i- j- 
    # (i_limit =0, j_limit=n-1)
    # (i_lim)

    print("printing in circular format \n")
    m =  no_row 
    n = no_col
    top, bottom , left, right = 0, m-1,0,n-1
    while top <= bottom and left <= right:
        for i in range(top,right+1):
            print(matrix[top][i],end = " ")
        top +=1
        for i in range(top,bottom+1):
            print(matrix[i][right],end = " ")
        right -= 1

        if top <= bottom:
            for i in range(right,left-1,-1):
                print(matrix[bottom][i],end = " ")
            bottom -= 1
        if left <= right:
            for i in range(bottom,top-1,-1):
                print(matrix[i][left],end = " ")
            left += 1
    
    ##
    print("\nformat change\n")
    # (0,0) (0,1),(1,0),(2,0),(1,1),(0,2),(0,3),(1,2)

    ## number of diagnonals 
    diag = 2*m -1 
    print(diag)
    import math
    # 4-(4-3+1) 5-5-3+2 
    diag_len = [i if i <=m else (diag+1 - i) for i in range(1,diag+1)]
    print(diag_len)
    
    
    #while 
    




