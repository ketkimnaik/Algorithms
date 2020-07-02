class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int find(int i, vector<int> & parent) {
        if(parent[i] == i) {
            return i;
        } 
        parent[i] = find(parent[i], parent);
        return parent[i];
    }
    
    void Union(int i, int j, vector<int> &parent, vector<int> &rank) {
        int xset = find(i, parent);
        int yset = find(j, parent);
        
        if(xset == yset) return;
        
        if(rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if(rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset] += 1;
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        vector<int> parent(size);
        vector<int> rank(size, 0);
        
        for(int i = 0; i < size; ++i) {
            parent[i] = i;
        }
        
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(M[i][j] == 1) {
                    Union(i, j, parent, rank);
                }
            }
        }
        
        set<int> result{};
        
        for(int i = 0; i < parent.size(); ++i) {
            // cout<<parent[i] <<endl;
            parent[i] = find(i,parent);
            result.insert(parent[i]);
        }
        
        return result.size();
    }
};