class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char maps[128] = {0};
        char mapt[128] = {0};
        for(int i = 0; i < s.length(); i++) {
            if(maps[s[i]] != mapt[t[i]]) return false;
            maps[s[i]] = i+1;
            mapt[t[i]] = i+1;
        }
        return true;
    }
};

Brute Force:

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> mp;
        unordered_map<char, int> visited;
        
        for(int  i = 0; i < s.size(); ++i) {
            if(mp.find(s[i]) == mp.end()) {
                if(visited[t[i]] ) {
                    return false;
                } else {
                    mp[s[i]] = t[i];
                    visited[t[i]] = 1;
                }
                
            } else {
                if(mp[s[i]] != t[i] ) return false;
            }
        }
        
        return true;
    }
};