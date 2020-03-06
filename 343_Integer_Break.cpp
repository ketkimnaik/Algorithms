class Solution {
public:
    int integerBreak(int n) {
        
        vector<int>dp;
        
        for(int i=0;i<=n;++i)
        {
            int maxi=0;
            for(int j=0;j<i;++j)
            {
                int temp_max=dp[j]*(i-j);
                
                if(temp_max>maxi)
                {
                    maxi=temp_max;
                }
            }
            
            if(i<n)
            {
                maxi=max(i,maxi);
                
            }
            
            dp.push_back(maxi);
        }
        
        return dp[n];
    }
};