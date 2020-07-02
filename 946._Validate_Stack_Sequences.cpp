class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int push_size = pushed.size();
        int pop_size = popped.size();
        int j = 0;
        
        for(int i = 0; i < push_size ; ++i) {
            s.push(pushed[i]);
            
            while(!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        
        if(j == pop_size)
            return true;
        
        return false;
    }
};