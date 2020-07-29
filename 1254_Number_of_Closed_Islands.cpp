class Solution {
public:
    void DFS(vector<vector<int>>& grid, int row, int col, int i, int j) {
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 1) return ;
        
        grid[i][j] = 1;
        
        DFS(grid, row, col, i + 1, j);
        DFS(grid, row, col, i - 1, j);
        DFS(grid, row, col, i, j - 1);
        DFS(grid, row, col, i, j + 1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        if(grid.empty()) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        
        
        for(int i = 0; i < row ; ++i) {
            for(int j = 0; j < col; ++j) {
                if(i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    DFS(grid, row, col, i, j); 
                }
            }
        }
        
        for(int i = 0; i < row ; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 0) {
                    DFS(grid, row, col, i, j); 
                    count++;
                }
            }
        }
        
       
        
        return count;
    }
}; 