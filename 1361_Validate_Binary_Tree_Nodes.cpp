class Solution {
public:
    public:
    bool global = true;
    void dfs(int src,vector<int>& leftChild,vector<int>& rightChild,vector<bool>& visited)
    {
        if(visited[src]) {
            global = false;
            return ;
        };
        visited[src] = true;
        if(leftChild[src]!=-1)
             dfs(leftChild[src],leftChild,rightChild,visited);
        if(rightChild[src]!=-1 )
             dfs(rightChild[src],leftChild,rightChild,visited);
    }
   
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        if(n<=1)
            return true;
        
      
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i] !=-1 || rightChild[i] !=-1)
            {
                dfs(i,leftChild,rightChild,visited);
                break;
            }
        
        }
        
            if(all_of(visited.begin(),visited.end(),[](bool a){return a;}) and global)
                return true;
       
        
        
        
        return false;
        
        
        
    }
};