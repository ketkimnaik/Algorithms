class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> mp;
        
        for(auto& i: S)
        {
            mp[i]++;
        }
        
        int result=0;
        for(auto &i:J)
        {
            result+=mp[i];
        }
        
        return result;
        
    }
};