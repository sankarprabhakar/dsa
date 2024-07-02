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
    lr_start = 0
    lr_end = no_col #-1
    row_count_top = 0

    tb_start = 1
    tb_end = no_row # - 1
    col_count_right = no_row -1
    rl_start = no_col- 2
    rl_end = 0
    row_count_bottom = no_row - 1
    bt_start = no_row - 2
    bt_end = 1
    col_count_left = 0
    while True:
        if row_count_top <= row_count_bottom and lr_start <= lr_end:
            for i in range(lr_start,lr_end):
                print(matrix[row_count_top][i], end = " ")
            row_count_top += 1
            lr_start+=1
            lr_end-=1

        if col_count_left <= col_count_right and tb_start <= tb_end:
            for i in range(tb_start,tb_end):
                print(matrix[i][col_count_right], end=" ")
            col_count_right -= 1
            tb_start +=1
            tb_end -= 1
        
        if row_count_bottom >= row_count_top and rl_start >= rl_end:
            for i in range(rl_end,rl_start+1,-1):
                print(matrix[i][row_count_bottom], end= " ")
            row_count_bottom -= 1
            rl_start-=1
            rl_end+=1
        
        
        if col_count_right >= col_count_left and bt_start >= bt_end:
            for i in range(bt_start,bt_end+1,-1):
                print(matrix[i][col_count_left], end = " ")
            col_count_left += 1
            bt_start +=1
            bt_end -= 1



