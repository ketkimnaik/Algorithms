class Solution {
public:
    bool valid(int x, int y, int row, int col) {
        return (x >=0 && x < row && y >=0 && y < col);
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> temp(row, vector<int> (col, 0));

        int count ;
        vector<int> X{-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> Y{-1, 0, 1, 1, 1, 0, -1, -1};
        int temp_x, temp_y;
        
        for(int  i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                count = 0;
                
                for(int k = 0; k < 8; ++k) {
                    temp_x = i + X[k];
                    temp_y = j + Y[k];
                    if (valid(temp_x, temp_y, row, col) && board[temp_x][temp_y] == 1) {
                        count++;
                    }
                }
                
                if(board[i][j] == 0) {
                    if(count == 3) {
                        temp[i][j] = 1;
                    } 
                } else {
                    if(count < 2 || count > 3) {
                        temp[i][j] = 0;
                    } else {
                        temp[i][j] = 1;
                    }
                }
            }
        }
        
        board = temp;
    }
};