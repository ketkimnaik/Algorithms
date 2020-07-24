class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if (k < 0) return 0;
        
        int count = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        
        int diff;
        
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            diff = it->first - k;
            
            if (mp.find(diff) != mp.end()) {
                if(it->first == diff && it->second > 1) {
                    count++;
                } else if (it->first != diff && it->second >= 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};