if __name__ == "__main__":
    matrix = [[1,2,4],[4,5,6],[7,8,9]]

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