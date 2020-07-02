class Solution {
    vector<int> parent;
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int Find(int i) {
        if(parent[i] == i) {
            return parent[i];
        }
        
        parent[i] = Find(parent[i]);
        return parent[i];
    }
    
    void UnionFind(int i, int j) {
        parent[Find(i)] = Find(j);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> row, col;
        parent = {};
        for(int i = 0; i < stones.size(); ++i) {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        
        for(int i = 0; i < stones.size(); ++i) {
            parent.push_back(i);
        }
        for(int i = 0; i < stones.size(); ++i) {
            for(auto j : row[stones[i][0]]) {
                UnionFind(i, j);
            }
            
            for(auto j : col[stones[i][1]]) {
                UnionFind(i, j);
            }
        }
        
        
        unordered_set<int> st;
        for(int i = 0; i < stones.size(); ++i) {
            parent[i] = Find(parent[i]);
            st.insert(parent[i]);
        }
        
        return stones.size() - st.size();
    }
};