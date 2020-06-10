class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(size, 1);
        dp[0] = 1;
        int result = 1;
        
        for(int i = 1; i < size; ++i) {
            for(int j = 0; j < i; ++j){
                if(pairs[i][0] > pairs[j][1] && (dp[j] + 1 > dp[i]))
                    dp[i] = 1 + dp[j];
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};