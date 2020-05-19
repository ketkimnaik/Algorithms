class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n=books.size();
        if(n==0)
            return 0;
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
           int ht=0,wd=0;
            
            for(int j=i-1;j>=0;--j)
            {
                wd+=books[j][0];
                if(wd>shelf_width)
                    break;
                ht=max(ht,books[j][1]);
                dp[i]=min(dp[i],ht+dp[j]);
            }
        }
        return dp[n];
    }
};