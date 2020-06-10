class Solution {
    double dp[102][102]={};
public:
    double Helper(vector<int>& A, int K, int n) {
        if(dp[n][K] != 0)
            return dp[n][K];
        
        if(n < K)
            return 0;
        
        double sum = 0;
        
        for(int i = n - 1; i >= 1; --i) {
            sum += A[i];
            dp[n][K] = max(dp[n][K], Helper(A, K-1, i) + (sum / (n - i)));
        }
        
        return dp[n][K];
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        double sum = 0;
        //vector<vector<double>> dp(n, vector<double>(K, 0));
        
        for(int  i = 0; i < n; ++i) {
            sum += A[i];
            dp[i + 1][1] = sum / (i + 1);
        }
        
        return Helper(A, K, n);
            
    }
};