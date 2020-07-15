class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int result = 0;
        
        for(auto n : nums) {
            count[n]++;
        }
        
        for(auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > 1) {
                
                result += (((it->second) * (it->second - 1)) / 2);
            }
        }
        
        return result;
    }
};