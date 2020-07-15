class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(k > s.size()) return 0;
        
        if(k == 0) return s.size();
        
        vector<int> count(26, 0);
        
        for(auto i : s) {
            count[i - 'a']++;
        }
        
        int i = 0;
        
        while(i < s.size() && count[s[i] - 'a'] >= k) {
            i++;
        }
        
        if(i == s.size()) return s.size();
        
        int left = longestSubstring(s.substr(0, i), k);
        
        while(i + 1 < s.size() && count[s[i] - 'a'] < k) {
            i++;
        }
        
        int right = longestSubstring(s.substr(i), k);
        
        return max(left, right);
    }
};