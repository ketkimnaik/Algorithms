class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result{};
        for(auto &i : nums) {
            if(nums[abs(i) - 1] < 0) continue;
            
            nums[abs(i) - 1] = nums[abs(i) - 1] * -1;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
        
    }
};