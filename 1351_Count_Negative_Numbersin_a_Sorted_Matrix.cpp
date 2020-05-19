class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int sum=0;
        
        for(int i=grid.size()-1;i>=0;--i)
        {
            for(int j= grid[i].size()-1;j>=0;--j)
            {
                if(grid[i][j] >=0)
                    break;
                else
                    sum+=1;
            }
        }
        
        return sum;
    }
};