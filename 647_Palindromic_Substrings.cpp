Optimal Solution:


class Solution {
public:
    int countSubstrings(string s) {
        
        int count=0;
        
        for(int i=0;i<s.size();++i)
        {
            int left;
            int right;
            
            left=i;
            right=i;
            
            while(left>=0 && right <s.size() && s[left]==s[right])
            {
                ++count;
                --left;
                ++right;
            }
            
            left=i;
            right=i+1;
            
           while(left>=0 && right <s.size() && s[left]==s[right])
            {
                ++count;
                --left;
                ++right;
            }
            
            
                
        }
        
        return count;
        
    }
};


DP Solution:

class Solution {
public:
    int countSubstrings(string s) {
        
        vector<vector<int>> dp(s.size(),vector<int> (s.size(),0));
        for(int i=0;i<s.size();++i)
        {
            dp[i][i]=1;
        }
        
        for(int i=1;i<s.size();++i)
        {
            for(int j=0;j<s.size()-i;++j)
            {
                int k=i+j;
                
                if(k-j+1==2)
                {
                    if(s[j]==s[k])
                        dp[j][k]=1;
                }
                else
                {
                    if(s[j]==s[k]  && dp[j+1][k-1]==1)
                        dp[j][k]=1;
                }
            }
        }
        int result=0;
        for(int i=0;i<s.size();++i)
        {
            for(int j=0;j<s.size();++j)
                
            {
                if(dp[i][j]==1)
                    result+=1;
            }
        }
        return result;
    }
};