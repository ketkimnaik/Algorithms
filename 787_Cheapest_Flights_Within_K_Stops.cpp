class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        vector<int> temp;
            
        for(int j = 0; j <= K; ++j) {
            temp = dist;
            for(auto &i : flights) {
                
                temp[i[1]] = min(temp[i[1]], dist[i[0]] + i[2]);
            }
            
            dist = temp;
        }
        
        if(dist[dst] == 1e8)
            return -1;
        
        return dist[dst];
        
    }
};