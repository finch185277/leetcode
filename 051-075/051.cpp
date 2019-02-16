class Solution {
private: // by @prime_tang
  bool is_valid(const std::vector<std::string> &nqueens, const int row,
                const int col, const int &n) {
    for (int i = 0; i < row; i++)
      if (nqueens.at(i).at(col) == 'Q')
        return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
      if (nqueens.at(i).at(j) == 'Q')
        return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
      if (nqueens.at(i).at(j) == 'Q')
        return false;
    return true;
  }
  void solve(std::vector<std::vector<std::string>> &ret,
             std::vector<std::string> &nqueens, const int row, const int &n) {
    if (row == n) {
      ret.push_back(nqueens);
      return;
    }
    for (int col = 0; col < n; col++) {
      if (is_valid(nqueens, row, col, n)) {
        nqueens.at(row).at(col) = 'Q';
        solve(ret, nqueens, row + 1, n);
        nqueens.at(row).at(col) = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> ret;
    std::vector<std::string> nqueens(n, std::string(n, '.'));
    solve(ret, nqueens, 0, n);
    return ret;
  }
};
