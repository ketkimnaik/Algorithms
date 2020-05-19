class Solution {
public:
    int minimumDeleteSum(string &s1, string &s2) {
        int n = s1.size() , m = s2.size();
        int dp[n+1][m+1];
        dp[0][0] = 0;
        for(int i=1;i<=n;i++)
            dp[i][0] = s1[i-1]+dp[i-1][0];
        for(int i=1;i<=m;i++)
            dp[0][i] = s2[i-1]+dp[0][i-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j]+s1[i-1],s2[j-1]+dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

Method 2:
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (s1[i]==s2[j])
                    dp[i][j]=(i-1>=0 && j-1>=0 ? dp[i-1][j-1] : 0)+s1[i];
                else
                    dp[i][j]=max((i-1>=0 ? dp[i-1][j] : 0),(j-1>=0 ? dp[i][j-1] : 0));
        int res=0;
        for (int i=0; i<n; i++)
            res+=s1[i];
        for (int i=0; i<m; i++)
            res+=s2[i];
        res-=2*dp[n-1][m-1];
        return res;
    }
};