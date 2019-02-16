class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    std::vector<std::vector<int>> after(matrix);
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.front().size(); j++) {
        if (matrix.at(i).at(j) == 0) {
          for (int x = 0; x < matrix.size(); x++)
            after.at(x).at(j) = 0;
          for (int y = 0; y < matrix.at(i).size(); y++)
            after.at(i).at(y) = 0;
        }
      }
    }
    matrix = after;
  }
};
