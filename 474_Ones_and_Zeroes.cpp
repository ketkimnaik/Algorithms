class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(auto &s: strs)
        {
            int curr_zero=0,curr_one=0;
            for(auto a: s)
                a=='0'?curr_zero++:curr_one++;
            
            for(int i=m;i>=curr_zero;--i)
            {
                for(int j=n;j>=curr_one;--j)
                {
                    dp[i][j]=max(dp[i-curr_zero][j-curr_one]+1,dp[i][j]);
                }
                
            }
            
        }
        
        return dp[m][n];
    }
};