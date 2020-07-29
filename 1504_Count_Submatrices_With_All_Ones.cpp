class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if(mat.empty()) return 0;
        
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row, vector<int> (col, 0));
        
        for(int i = 1; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(mat[i][j] == 1) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }
        
        int temp, ans = 0;
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                
                temp = mat[i][j];
                
                for(int k = j; k < col; ++k) {
                    temp = min(temp, mat[i][k]);
                    ans += temp;
                    
                }
                
                
            }
        }
        
        return ans;
    }
};	