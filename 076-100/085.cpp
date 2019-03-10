class Solution {
public: // by @morrischen2008
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty())
      return 0;
    const int m = matrix.size(), n = matrix.front().size();
    std::vector<int> left(n, 0), right(n, n), height(n, 0);
    int max_area = 0;
    for (int i = 0; i < m; i++) {
      int cur_left = 0, cur_right = n;
      for (int j = 0; j < n; j++) {
        if (matrix.at(i).at(j) == '1')
          height.at(j)++;
        else
          height.at(j) = 0;
      }
      for (int j = 0; j < n; j++) {
        if (matrix.at(i).at(j) == '1')
          left.at(j) = std::max(left.at(j), cur_left);
        else {
          left.at(j) = 0;
          cur_left = j + 1;
        }
      }
      for (int j = n - 1; j >= 0; j--) {
        if (matrix.at(i).at(j) == '1')
          right.at(j) = std::min(right.at(j), cur_right);
        else {
          right.at(j) = n;
          cur_right = j;
        }
      }
      for (int j = 0; j < n; j++)
        max_area =
            std::max(max_area, (right.at(j) - left.at(j)) * height.at(j));
    }
    return max_area;
  }
};
