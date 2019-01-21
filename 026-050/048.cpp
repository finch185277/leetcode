class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size() / 2 + matrix.size() % 2; i++) {
      for (int j = 0; j < matrix.size() / 2; j++) {
        std::vector<int> cache(4);
        int row = i;
        int col = j;
        for (int k = 0; k < 4; k++) {
          cache.at(k) = matrix.at(row).at(col);
          int x = row;
          row = col;
          col = matrix.size() - 1 - x;
        }
        for (int k = 0; k < 4; k++) {
          matrix.at(row).at(col) = cache.at((k + 3) % 4);
          int x = row;
          row = col;
          col = matrix.size() - 1 - x;
        }
      }
    }
  }
};
