class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result=[]
        rows,cols=0,-1
        dir_row,dir_col=0,1 #direction for rows and cols
        steps=0
        row_step,col_step=len(matrix[0]),len(matrix)-1
        
        for i in range(len(matrix[0])*len(matrix)):
            rows+=dir_row
            cols+=dir_col
            result.append(matrix[rows][cols])
            steps+=1
            
            if (dir_col!=0 and steps==row_step) or (dir_row!=0 and steps==col_step): # to change the direction
                if dir_col!=0:
                    row_step-=1
                else:
                    col_step-=1
                dir_row,dir_col=dir_col,-dir_row
                steps=0
        return result