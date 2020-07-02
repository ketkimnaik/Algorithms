class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        
        for(auto &i : asteroids) {
            if(! stk.empty()) {
                if(stk.top() > 0 && i < 0) {
                    if(abs(i) == stk.top()) {
                        stk.pop();
                    } else if(abs(i) > stk.top()){
                        while(! stk.empty() && abs(i) > stk.top() && stk.top() > 0) {
                            stk.pop();
                        }
                        
                        if(stk.empty() || stk.top() < 0) {
                            stk.push(i);
                        } else if(!stk.empty() && stk.top() == abs(i)) {
                            stk.pop();
                        }
                    }
                } else {
                    stk.push(i);
                }
                    
            } else {
                stk.push(i);
            }
            
        }
        
        vector<int> result{};
        
        while(! stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};