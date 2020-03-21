class UnionFind{
    
    vector<int> parent;
    vector<int> degree;
    
    public:
    UnionFind(int n):parent(n+1),degree(n+1,1)
    {
        //set parent node for each node 
        for(int i=0;i<=n;++i)
        {
            parent[i]=i;
        }
    }
    
    //find the ultimate parent node for each node
    int find(int n)
    {
        if(parent[n] !=n)
        {
            parent[n]=find(parent[n]);
        }
        
        return parent[n];
    }
    
    void Union(int n1,int n2)
    {
        int a=find(n1);
        int b=find(n2);
        
        if(degree[a]>degree[b])
            parent[b]=a;
        else if(degree[b]>degree[a])
            parent[a]=b;
        else 
        {
            if(degree[a]==degree[b])
            {
                parent[b]=a;
                ++degree[a];
            }
            
        }
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       
        int nodes=0;
        
        //find number of nodes
        for(int i=0;i<edges.size();++i)
        {
            nodes=max(nodes,edges[i][0]);
            nodes=max(nodes,edges[i][1]);
            
        }
        
        UnionFind u(nodes);
        
        for(int i=0;i<edges.size();++i)
        {
            if(u.find(edges[i][0])==u.find(edges[i][1]))
                return edges[i];
            
            u.Union(edges[i][0],edges[i][1]);
        }
        
        return vector<int>{-1,-1};
        
    }
};