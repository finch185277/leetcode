class Solution {
private:
  inline static bool cmp(const std::vector<int> &vec, const int x) {
    return vec.back() < x;
  }

public: // by @MissMary
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix.front().empty())
      return false;
    auto itr = std::lower_bound(matrix.begin(), matrix.end(), target, cmp);
    return itr != matrix.end() &&
           std::binary_search(itr->begin(), itr->end(), target);
    return true;
  }
};
