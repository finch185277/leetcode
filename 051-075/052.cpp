class Solution {
private:
  bool is_valid(const std::vector<std::vector<bool>> &nqueens, const int row,
                const int col, const int &n) {
    for (int i = 0; i < row; i++)
      if (nqueens.at(i).at(col))
        return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
      if (nqueens.at(i).at(j))
        return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
      if (nqueens.at(i).at(j))
        return false;
    return true;
  }
  void solve(int &count, std::vector<std::vector<bool>> &nqueens, const int row,
             const int &n) {
    if (row == n) {
      count++;
      return;
    }
    for (int col = 0; col < n; col++) {
      if (is_valid(nqueens, row, col, n)) {
        nqueens.at(row).at(col) = true;
        solve(count, nqueens, row + 1, n);
        nqueens.at(row).at(col) = false;
      }
    }
  }

public:
  int totalNQueens(int n) {
    int count = 0;
    std::vector<std::vector<bool>> nqueens(n, std::vector(n, false));
    solve(count, nqueens, 0, n);
    return count;
  }
};
