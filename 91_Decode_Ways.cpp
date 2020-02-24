class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int n=s.length();
        vector<int> dp(n+1);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int first=stoi(s.substr(i-1,1));//only 1 digit integer
            int second=stoi(s.substr(i-2,2));//two digit integer
            
            if(first>=1)
                dp[i]=dp[i]+dp[i-1];
            
            if(second>=10 && second<=26)
                dp[i]=dp[i]+dp[i-2];
        }
        
        return dp[n];
    }
};