class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result{};
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<groupSizes.size();++i)
        {
            int key=groupSizes[i];
            if(mp.count(key) > 0)
            {
                mp[key].push_back(i);
            }
            else
            {
                mp[key]=vector<int> {i};
            }
            
            if(mp[key].size()==key)
            {
                result.push_back(mp[key]);
                mp.erase(key);
            }
        }
        return result;
    }
};