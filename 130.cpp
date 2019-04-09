class Solution {
private:
  void check(std::vector<std::vector<char>> &board, int i, int j, int row,
             int col) {
    if (board.at(i).at(j) == 'O') {
      board.at(i).at(j) = '*';
      if (i > 1)
        check(board, i - 1, j, row, col);
      if (j > 1)
        check(board, i, j - 1, row, col);
      if (i + 1 < row)
        check(board, i + 1, j, row, col);
      if (j + 1 < col)
        check(board, i, j + 1, row, col);
    }
  }

public: // by @sugeladi
  void solve(vector<vector<char>> &board) {
    if (board.empty() || board.front().empty())
      return;
    int i, j, row = board.size(), col = board.front().size();
    for (i = 0; i < row; i++) {
      check(board, i, 0, row, col);
      if (col > 1)
        check(board, i, col - 1, row, col);
    }
    for (j = 1; j + 1 < col; j++) {
      check(board, 0, j, row, col);
      if (row > 1)
        check(board, row - 1, j, row, col);
    }
    for (i = 0; i < row; i++)
      for (j = 0; j < col; j++)
        if (board.at(i).at(j) == 'O')
          board.at(i).at(j) = 'X';
    for (i = 0; i < row; i++)
      for (j = 0; j < col; j++)
        if (board.at(i).at(j) == '*')
          board.at(i).at(j) = 'O';
  }
};
