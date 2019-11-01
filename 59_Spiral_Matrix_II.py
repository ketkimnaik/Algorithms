class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        d_rows=0 # for direction of rows
        d_cols=1 # for direction of columns
        rows=0
        cols=0
        
        spiral=[[0 for i in range(n)] for j in range(n)] # generate matrix with all zeros
        k=1
        while k<=n*n:
            spiral[rows][cols]=k
            k+=1
            if rows<0 or rows+d_rows>=n or cols<0 or cols+d_cols>=n or spiral[rows+d_rows][cols+d_cols]!=0:
                d_rows,d_cols=d_cols,-d_rows
                
            rows+=d_rows
            cols+=d_cols
        return spiral
                
                
        
        