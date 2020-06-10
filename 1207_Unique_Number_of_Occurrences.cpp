class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_map<int,int> mp;
        
        for(auto &i : arr)
            m[i]++;
        
        for(auto it = m.begin(); it != m.end(); ++it) {
            mp[it->second]++;
            if(mp[it->second] > 1)
                return false;
        }
            
        return true;
    }
};