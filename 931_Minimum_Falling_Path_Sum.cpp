class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int i=0;i<n;++i)
            dp[0][i]=A[0][i];
        
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(j==0)
                {
                    dp[i][j]=A[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==n-1)
                {
                    dp[i][j]=A[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                
                else
                {
                    dp[i][j]=A[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                }
            }
        }
        
        return *min_element(dp[n-1].begin(),dp[n-1].end());
        
    }
};