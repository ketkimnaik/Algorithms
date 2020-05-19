class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        
        int n=A.size();
        
        if(n==0)
            return 0;
        vector<int> dp(n,0);
        
        int maximum=A[0];
        dp[0]=A[0];
        
        for(int i=1;i<K;++i)
        {
            maximum=max(maximum,A[i]);
            dp[i]=maximum*(i+1);
        }
        
        if(K==n)
            return dp[n-1];
        
        
        
        for(int i=K;i<A.size();++i)
        {
            maximum=A[i];
            for(int j=1;j<=K;++j)
            {
                maximum=max(maximum,A[i-j+1]);
                dp[i]=max(dp[i],dp[i-j]+j*maximum);
            }
        }
        
        return dp[n-1];
        
    }
};