Optimized Approach:

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return 0;
        int count=0,l=0;
        int diff=A[1]-A[0];
        
        for(int i=2;i<n;++i)
        {
            if(A[i]-A[i-1]==diff)
                count+=++l;
            else
            {
                l=0;
                diff=A[i]-A[i-1];
            }
        }
        
        return count;
        
    }
};

DP Approach:

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;++i)
            dp[i][i]=true;
        
        int count=0;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<n-i;++j)
            {
                int k=j+i;
                if(k-j+1==2)
                    dp[j][k]=true;
                
                else
                {
                    dp[j][k]= (A[k]-A[k-1]==A[k-1]-A[k-2]) && (dp[j][k-1]==true);
                    if(dp[j][k])
                        count+=1;
                }
            }
        }
        
        return count;
    }
};