class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        for(int i = 0; i < answers.size(); ++i) {
            mp[answers[i]]++;
        }
        
        int result = 0;
        
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            
            result += ((it->first + 1) * ceil((float)(it->second) / (float)(it -> first + 1)));
            
        }
        
        return result;
    }
};