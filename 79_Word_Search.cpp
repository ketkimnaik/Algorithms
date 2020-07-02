class Solution {
public:
    bool DFS(vector<vector<char>>& board, string &word, int index, int i, int j, int &row, int &col) {
        if(i < 0 || i >= row || j < 0 || j >= col) {
            return false;
        }
        
        if(word[index] != board[i][j]) {
            return false;
        }
        
        if(index >= word.size() - 1) {
            return true;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        bool result = DFS(board, word, index + 1, i + 1, j, row, col)
                     || DFS(board, word, index + 1, i - 1, j, row, col)
                     || DFS(board, word, index + 1, i, j + 1, row, col)
                     || DFS(board, word, index + 1, i, j - 1, row, col);
        board[i][j] = temp;
        
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(word[0] != board[i][j]) continue;
                if(DFS(board, word, 0, i, j, row, col)) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};