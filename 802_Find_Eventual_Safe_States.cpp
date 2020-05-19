class Solution {
public:
    bool Topological_sort(vector<vector<int>>& graph,vector<int> &dp,int node)
    {
        if(dp[node])
            return dp[node]==1;
        
        dp[node]=-1;
        
        for(auto it=graph[node].begin();it!=graph[node].end();++it)
        {
            if(!Topological_sort(graph,dp,*it))
                return false;
        }
        dp[node]=1;
        
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes=graph.size();
        vector<int> dp(nodes,0);
        vector<int> result{};
        for(int i=0;i<graph.size();++i)
        {
        if(Topological_sort(graph,dp,i))
            result.push_back(i);
            
        }
        
        return result;
    }
};