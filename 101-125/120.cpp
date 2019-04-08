class Solution {
public: // by @stellari
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
    std::vector<int> minlen(triangle.back());
    for (int layer = triangle.size() - 2; layer >= 0; layer--)
      for (int i = 0; i <= layer; i++)
        minlen.at(i) =
            std::min(minlen.at(i), minlen.at(i + 1)) + triangle.at(layer).at(i);
    return minlen.front();
  }
};
