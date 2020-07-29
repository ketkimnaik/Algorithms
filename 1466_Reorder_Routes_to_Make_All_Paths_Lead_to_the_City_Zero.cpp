class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        unordered_set<int> st;
        int ans = 0;
        st.insert(0);
        
        for(auto &c : connections){
            if (c[1] == 0) {
                st.insert(c[0]);
            }
        }
        
        while(st.size() != n) {
            for(auto &c : connections) {
                if (st.find(c[1]) == st.end()) {
                    if(st.find(c[0]) != st.end()) {
                        st.insert(c[1]);
                        ans++;
                    }
                    
                } else {
                    st.insert(c[0]);
                }
                
                if(st.size() == n) break;
            }
        }
        return ans;
    }
};