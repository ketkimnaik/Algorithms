class Solution {
public:
    void solve(vector<vector<char>>& board) {
    
    // get board dimension
    int row = board.size();
    int col = row ? board[0].size() : 0;
    
    // BFS for all boundary 'O' cells, and mark all connected 'O's to 'B's
    for (int r = 0; r < row; ++r)
      for (int c = 0; c < col; ++c) 
      {
        if ((r == 0 || r == row-1 || c == 0 || c == col-1)  && board[r][c] == 'O') 
          bfs(board, r, c, row, col);        
      }

    // Set all 'B's to 'O's, and everything else 'X'
    for (int r = 0; r < row; ++r)
      for (int c = 0; c < col; ++c) 
      {
        if (board[r][c] == 'B') 
          board[r][c] = 'O';
        else
          board[r][c] = 'X';        
      }
  }
  
  // BFS at cell(r, c) and mark all connected cells as 'B'
  void bfs(vector<vector<char>>& board, int r, int c, int row, int col) 
  {    
    board[r][c] = 'B';
    queue<pair<int, int>> q({make_pair(r, c)});
    
    while (!q.empty()) 
    {
      r = q.front().first, c = q.front().second;
      q.pop();
            
      if (r > 0     && board[r-1][c] == 'O') q.emplace(r-1, c), board[r-1][c] = 'B';
      if (r+1 < row && board[r+1][c] == 'O') q.emplace(r+1, c), board[r+1][c] = 'B';
      if (c > 0     && board[r][c-1] == 'O') q.emplace(r, c-1), board[r][c-1] = 'B';
      if (c+1 < col && board[r][c+1] == 'O') q.emplace(r, c+1), board[r][c+1] = 'B';
    }
  }
};