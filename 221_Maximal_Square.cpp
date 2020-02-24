class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=0;
        if(row !=0)
            col=matrix[0].size();
       
        int square=0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        
        for(int i=0;i<col;i++)
        {
            dp[0][i]=matrix[0][i]=='1'?1:0;
            square=max(square,dp[0][i]);
        }
        
        for(int j=1;j<row;j++)
        {
            dp[j][0]=matrix[j][0]=='1'?1:0;
            square=max(square,dp[j][0]);
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                
                square=max(square,dp[i][j]);
            }
        }
        
        return square*square;
    }
};