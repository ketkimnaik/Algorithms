class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
       //vector<vector<int>> result(row, vector<int> (col));
        int temp_row;
        int temp_col;
        vector<int> temp;
        
        for(int i = 0; i < col; ++i) {
            temp_row = 0;
            temp_col = i;
            //vector<int> temp{};
            temp = {};
            while(temp_row >= 0 && temp_row < row && temp_col >= 0 && temp_col < col) {
                temp.push_back(mat[temp_row][temp_col]);
                temp_row++;
                temp_col++;
            }
            
            sort(temp.begin(), temp.end());
            
            temp_row = 0;
            temp_col = i;
            int j = 0;
            while(temp_row >= 0 && temp_row < row && temp_col >=0 && temp_col < col) {
                mat[temp_row][temp_col] = temp[j];
                j++;
                temp_row++;
                temp_col++;
            }
            
        }
        
        for(int i = 1; i < row; ++i) {
            temp_row = i;
            temp_col = 0;
            //vector<int> temp{};
            temp = {};
            while(temp_row >= 0 && temp_row < row && temp_col >= 0 && temp_col < col) {
                temp.push_back(mat[temp_row][temp_col]);
                temp_row++;
                temp_col++;
            }
            
            sort(temp.begin(), temp.end());
            
            temp_row = i;
            temp_col = 0;
            int j = 0;
            //cout<<temp.size();
            while(temp_row >= 0 && temp_row < row && temp_col >=0 && temp_col < col) {
                //cout<<"hi";
                mat[temp_row][temp_col] = temp[j];
                j++;
                temp_row++;
                temp_col++;
            }
            
        }
        
        return mat;
    }
};