class Solution {
public: // by @tqlong
  int minCut(std::string s) {
    int n = s.size();
    std::vector<int> cut(n + 1, 0);
    for (int i = 0; i <= n; i++)
      cut.at(i) = i - 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
        cut.at(i + j + 1) = std::min(cut.at(i + j + 1), 1 + cut.at(i - j));
      for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j];
           j++)
        cut.at(i + j + 1) = std::min(cut.at(i + j + 1), 1 + cut.at(i - j + 1));
    }
    return cut.back();
  }
};
