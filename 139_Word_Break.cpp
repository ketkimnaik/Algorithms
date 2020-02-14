class Solution {
public:
   bool wordBreak(string s, vector<string>& wordDict) {
       int n =s.size();
       int m = wordDict.size();
       
       vector<bool> dp(n+1);
       dp[0]=true;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<wordDict.size();j++)
                 if( i+1>=wordDict[j].size() && dp[(i+1) - wordDict[j].size()] && s.substr((i+1) - wordDict[j].size(),wordDict[j].size()) == wordDict[j])
                    dp[i+1] = true;
       }
   
       return dp[n];
       
    }
};