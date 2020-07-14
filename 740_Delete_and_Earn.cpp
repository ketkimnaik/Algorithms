class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count_sum(10002);
        
        for(int i = 0; i < nums.size(); ++i) {
            count_sum[nums[i]] += nums[i];
        }
        
        vector<int> dp(10002, 0);
        
        dp[1] = count_sum[1];
        dp[2] = max(count_sum[1], count_sum[2]);
        
        for(int i = 3; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 2] + count_sum[i], dp[i - 1]);
        }
        
        return max(dp[10000], dp[9999]);
    }
};