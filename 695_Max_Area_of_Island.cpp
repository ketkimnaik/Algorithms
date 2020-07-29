class Solution {
public:
    int DFS(vector<vector<int>>& grid, int i, int j, int row, int col) {
        if(i < 0 || j < 0 || i >= row || j >= col) return 0;
        
        if(grid[i][j] == 0) return 0;
        
        int result = 1;
        
        grid[i][j] = 0;
        
        result += DFS(grid, i - 1, j, row, col) + DFS(grid, i + 1, j, row, col)
                    + DFS(grid, i, j - 1, row, col) + DFS(grid, i, j + 1, row, col);
        
        return result;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int max_area = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        
        for(int i = 0; i < row; ++i) {
            
            for(int j = 0; j < col; ++j) {
                
                if(grid[i][j] == 1) {
                    
                    int res = DFS(grid, i, j, row, col);
                    max_area = max(max_area, res);
                   
                }
                
            }
        }
    

        return max_area;
    }
};