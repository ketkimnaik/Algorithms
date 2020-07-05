class Solution {
public:
    bool Helper(string &q, string &p) {
        int i = 0, j = 0;
        
        while(i < q.size()) {
            if(j < p.size() && q[i] == p[j]) {
                i++;
                j++;
            } else {
                if(q[i] >= 'A' && q[i] <= 'Z') {
                    if(j == p.size()) return false;
                    return false;
                }
                i++;
            }
        }
        
        if(j == p.size()) return true;
        
        return false;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool> result{};
        
        for(auto &i : queries) {
            result.push_back(Helper(i, pattern));
        }
        
        return result;
    }
};