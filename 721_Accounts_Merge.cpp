class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        while(parent[x] != x) {
            x = parent[x];
        }
        
        return parent[x];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int size = accounts.size();
        
        if(size == 1) {
            sort(accounts[0].begin() + 1, accounts[0].end());
            return accounts;
        }
        
        parent = vector<int> (size, -1);
        vector<string> name(size);
        unordered_map<string, int> email;
        int i = 0;
        
        for(auto &a : accounts) {
            name[i] = a[0];
            parent[i] = i;
            
            for(int j = 1; j < a.size(); ++j) {
                if(email.find(a[j]) != email.end()) {
                    parent[find(i)] = find(email[a[j]]);
                } else {
                    email[a[j]] = i;
                }
            }
            i++;
        }
        
        unordered_map<int, vector<string>> merge;
        
        for(auto it = email.begin(); it != email.end(); ++it) {
            int p = find(parent[it->second]);
            merge[p].push_back(it->first);
        }
        
        vector<vector<string>> result;
    
        for(auto it = merge.begin(); it != merge.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            it->second.insert(it->second.begin(), name[it->first]);
            result.push_back(it->second);
        }
        
        return result;
    }
};