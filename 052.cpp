class Solution {
private:
  bool is_not_under_attack(int row, int col, int n, std::vector<int> &rows,
                           std::vector<int> &hills, std::vector<int> &dales) {
    int sum = rows.at(col) + hills.at(row - col + 2 * n) + dales.at(row + col);
    return (sum == 0) ? true : false;
  }
  int backtrack(int row, int count, int n, std::vector<int> &rows,
                std::vector<int> &hills, std::vector<int> &dales) {
    for (int col = 0; col < n; col++) {
      if (is_not_under_attack(row, col, n, rows, hills, dales)) {
        rows.at(col) = 1;
        hills.at(row - col + 2 * n) = 1;
        dales.at(row + col) = 1;
        if (row + 1 == n)
          count++;
        else
          count = backtrack(row + 1, count, n, rows, hills, dales);
        rows.at(col) = 0;
        hills.at(row - col + n * 2) = 0;
        dales.at(row + col) = 0;
      }
    }
    return count;
  }

public:
  int totalNQueens(int n) {
    std::vector<int> rows(n), hills(n * 4 - 1), dales(n * 2 - 1);
    return backtrack(0, 0, n, rows, hills, dales);
  }
};
