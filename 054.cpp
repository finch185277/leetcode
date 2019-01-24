class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    std::vector<int> ret;
    if (matrix.empty() || matrix.at(0).empty())
      return ret;
    int top = 0, bot = matrix.size() - 1;
    int lhs = 0, rhs = matrix.at(0).size() - 1;
    while (top <= bot && lhs <= rhs) {
      for (int col = lhs; col <= rhs; col++)
        ret.push_back(matrix.at(top).at(col));
      for (int row = top + 1; row <= bot; row++)
        ret.push_back(matrix.at(row).at(rhs));
      if (top < bot && lhs < rhs) {
        for (int col = rhs - 1; col > lhs; col--)
          ret.push_back(matrix.at(bot).at(col));
        for (int row = bot; row > top; row--)
          ret.push_back(matrix.at(row).at(lhs));
      }
      top++;
      bot--;
      lhs++;
      rhs--;
    }
    return ret;
  }
};
