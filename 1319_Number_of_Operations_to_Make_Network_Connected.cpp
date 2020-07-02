class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int find(int x, vector<int> &parent) 
    { 
        if (parent[x] != x) { 
            parent[x] = find(parent[x], parent); 
        } 
  
        return parent[x]; 
    } 
    
    void UnionFind(int a, int b, vector<int> &parent, vector<int> &rank) {
        
        int xset = find(a, parent);
        int yset = find(b, parent);
        
        // cout<<"uni";
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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for(auto &i : connections) {
            
            UnionFind(i[0], i[1], parent, rank);
            // cout<<"hi";
        }
        
        unordered_set<int> st{};
        
        for(int i = 0; i < n; ++i) {
            parent[i] = find(parent[i], parent);
            //cout<<parent[i] <<endl;
            st.insert(parent[i]);
        }
       // cout<<st.size();
        
        return st.size() - 1;
        
    }
};