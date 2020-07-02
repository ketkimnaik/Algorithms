class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        
        for(int i = 0; i < s.size(); ++i) {
            if(stk.empty()) {
                stk.push(make_pair(s[i], 1));
            } else {
                if(s[i] == stk.top().first) {
                    stk.top().second = stk.top().second + 1;
                    if(k == stk.top().second) {
                        stk.pop();
                    }
                        
                } else {
                    stk.push(make_pair(s[i], 1));
                }
            }
        }
        
        string result = "";
        
        while(! stk.empty()) {
            while(stk.top().second --) {
                result.push_back(stk.top().first);
            }
            stk.pop();
        }
         
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};