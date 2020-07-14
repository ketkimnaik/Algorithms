class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, result = 0;
        
        for(auto &i : nums) {
            sum += i;
            
            if(mp.find(sum - k) != mp.end()) {
                result += mp[sum - k];
            }
            
            mp[sum] += 1;
        }
        
        return result;
    }
};