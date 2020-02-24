class Solution {
public:
   
        int ff(vector<int>& nums, int start, int end) {
        int* dp = new int[end - start + 1];
        dp[0] = nums[start];
        dp[1] = max(dp[0], nums[start + 1]);
        
        for (int i=2; start + i < end; i++) {
            dp[i] = max(dp[i-2] + nums[start + i], dp[i-1]);
        }
        
        return dp[end - start - 1];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(ff(nums, 0, nums.size()-1), ff(nums, 1, nums.size()));
    }
};