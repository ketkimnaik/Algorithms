class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> mp;
        vector<int> visited(26, 0);
        stringstream ss(str);
        string temp;
        int i = 0;
        int count = 0;
        
        while(ss >> temp) {
            count++;
            if (i == pattern.size()) return false;
            
            if (mp.find(temp) == mp.end()) {
                if(visited[pattern[i] - 'a']) return false;
                mp[temp] = pattern[i];
                visited[pattern[i] - 'a'] = 1;
                i++;
            } else {
                if (mp[temp] != pattern[i]) {
                    return false;
                }
                i++;
                
            }
        }
        
        if (count != pattern.size()) return false;
        
        return true;
    }
};