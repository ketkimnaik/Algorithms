class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int per = 0;
        int n = grid.size();
        int m;
        if(n) m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    if (i == 0 || grid[i-1][j] != 1) per++;
                    if (j == 0 || grid[i][j-1] != 1) per++;
                    if (i == n-1 || grid[i+1][j] != 1) per++;
                    if (j == m-1 || grid[i][j+1] != 1) per++; 
                }
               
            }
        }
        return per;
            
    }
};

Using DFS:

class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int &ans, int &row, int &col) {
        if(i < 0 || i == row || j < 0 || j == col || grid[i][j] == 0) {
            ans++;
            return;
        }
        
        if(grid[i][j] == 2) {
            return;
        }
        
        grid[i][j] = 2;
        DFS(grid, i + 1, j, ans, row, col);
        DFS(grid, i - 1, j, ans, row, col);
        DFS(grid, i, j + 1, ans, row, col);
        DFS(grid, i, j - 1, ans, row, col);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col;
        if (row) {
            col = grid[0].size();
        }
        
        int ans = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 1) {
                    DFS(grid, i, j, ans, row, col);
                }
            }
        }
        
        return ans;
    }
};