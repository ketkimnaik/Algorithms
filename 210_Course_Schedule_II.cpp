class Solution {
public:
    vector<int> BFS(vector<vector<int>> &adj)
    {
        int visited=0;
        
        vector<int> degree(adj.size(),0);
        
        for(int i=0;i<adj.size();++i)
        {
            for(int j=0;j<adj[i].size();++j)
            {
                ++degree[adj[i][j]];
            }
        }
        
        queue<int> q;
        vector<int> result;
        for(int i=0;i<degree.size();++i)
        {
            if(degree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int a=q.front();
            ++visited;
            q.pop();
            result.emplace_back(a);
            for(int i=0;i<adj[a].size();++i)
            {
                --degree[adj[a][i]];
                if(degree[adj[a][i]]==0)
                {
                    q.push(adj[a][i]);
                }
            }
        }
        
        reverse(result.begin(),result.end());
        
        return visited==adj.size()? result:vector<int>{};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(numCourses==0)
            return {};
        
        vector<vector<int>> adj(numCourses);
        
        for(auto &e:prerequisites )
        {
            adj[e[0]].emplace_back(e[1]);
        }
        vector<int> result=BFS(adj);
        
        return result;
    }
};