class Solution {
    
    bool BFS(vector<int> &color,vector<vector<int>>& graph,int source)
    {
        color[source]=1;
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto &i: graph[u])
            {
                if(color[i]==-1)
                {
                    color[i]=1-color[u];
                    q.push(i);
                }
                else if(color[i]==color[u])
                    return false;
                
            }
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();//number of vertices
        vector<int> color(v,-1);
        for(int i=0;i<v;++i)
        {
            if(color[i]==-1)
            {
                if(!BFS(color,graph,i))
                    return false;
            }
        }
        
        return true;
    }
};