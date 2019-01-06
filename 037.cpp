class Solution {
private: // from discuss: 15853
  inline bool check(std::vector<std::vector<char>> &board, int i, int j,
                    char val) {
    int row = i - i % 3, col = j - j % 3;
    for (int x = 0; x < 9; x++) // same column
      if (board.at(x).at(j) == val)
        return false;
    for (int y = 0; y < 9; y++) // same row
      if (board.at(i).at(y) == val)
        return false;
    for (int x = 0; x < 3; x++) // same block
      for (int y = 0; y < 3; y++)
        if (board.at(row + x).at(col + y) == val)
          return false;
    return true;
  }
  inline bool solve(std::vector<std::vector<char>> &board, int i, int j) {
    if (i == 9) // buttom upper bound
      return true;
    if (j == 9) // right upper bound
      return solve(board, i + 1, 0);
    if (board.at(i).at(j) != '.')
      return solve(board, i, j + 1);
    for (char c = '1'; c <= '9'; c++) { // if current cell unknown
      if (check(board, i, j, c)) {      // DFS
        board.at(i).at(j) = c;
        if (solve(board, i, j + 1))
          return true;
        board.at(i).at(j) = '.'; // back and forward
      }
    }
    return false;
  }

public:
  inline void solveSudoku(vector<vector<char>> &board) { solve(board, 0, 0); }
};
