class Solution {
public:
    bool Helper(vector<int>& nums, int k, int target, int index, int current_sum, vector<bool> visited) {
        if(k == 0) return true;
        
        if(current_sum == target) {
            return Helper(nums, k - 1, target, 0, 0, visited);
        }
        
        for(int i = index; i < nums.size(); ++i) {
            if(! visited[i] && current_sum + nums[i] <= target) {
                visited[i] = true;
                if(Helper(nums, k , target, i + 1, current_sum + nums[i], visited))  return true;
                visited[i] = false;

            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int max_elem = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            max_elem = max(max_elem, nums[i]);
        }
        
        if(max_elem > sum / k || sum % k != 0) {
            return false;
        }
        vector<bool> visited(nums.size(), false);
        return Helper(nums, k, sum / k, 0, 0, visited);
    }
};