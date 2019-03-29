class Solution {
public: // by Approach 1: Dynamic Programming
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ret;
    if (numRows != 0) {
      ret.emplace_back();
      ret.front().push_back(1);
      for (int i = 1; i < numRows; i++) {
        std::vector<int> row, prerow = ret.at(i - 1);
        row.push_back(1);
        for (int j = 1; j < i; j++)
          row.push_back(prerow.at(j - 1) + prerow.at(j));
        row.push_back(1);
        ret.push_back(row);
      }
    }
    return ret;
  }
};
