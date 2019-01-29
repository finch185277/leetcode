class Solution {
public: // by @AllenYick
  vector<vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> ret(n, std::vector<int>(n));
    int k = 1, i = 0;
    while (k <= n * n) {
      int j = i;
      while (j < n - i) // left to right
        ret.at(i).at(j++) = k++;
      j = i + 1;
      while (j < n - i) // top to bottom
        ret.at(j++).at(n - i - 1) = k++;
      j = n - i - 2;
      while (j > i) // right to left
        ret.at(n - i - 1).at(j--) = k++;
      j = n - i - 1;
      while (j > i) // bottom to top
        ret.at(j--).at(i) = k++;
      i++;
    }
    return ret;
  }
};
