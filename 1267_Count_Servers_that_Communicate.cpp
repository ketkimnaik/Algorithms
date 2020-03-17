class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        if(grid.size()==0)
            return 0;
        if(grid.size()==1 && grid[0].size()==1 && grid[0][0]==1)
            return 1;
        vector<int> row(grid.size(),0);
        vector<int>col(grid[0].size(),0);
        
        int cr;
        
        
        for(int i=0;i< grid.size();++i)
        {   cr=0;
            for(int j=0;j<grid[0].size();++j)
            {
                
                if(grid[i][j]==1)
                    cr+=1;
                if(cr==2)
                {
                    
                    row[i]=1;
                    break;
                }
            }
        }
        
        for(int i=0;i< grid[0].size();++i)
        {cr=0;
            for(int j=0;j<grid.size();++j)
            {
                
                if(grid[j][i]==1)
                    cr++;
                if(cr==2)
                {
                    col[i]=1;
                    break;
                }
            }
        }
        int result=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if( grid[i][j]==1 && (row[i]==1 || col[j]==1) )
                  result++;  
            }
        }
        return result;
    }
};