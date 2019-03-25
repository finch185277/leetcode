class Solution {
public: // by @balint
  int numDistinct(std::string s, std::string t) {
    std::vector<std::vector<long long>> dp(
        t.size() + 1, std::vector<long long>(s.size() + 1));
    for (int j = 0; j <= s.size(); j++)
      dp.front().at(j) = 1;
    for (int i = 0; i < t.size(); i++) {
      for (int j = 0; j < s.size(); j++) {
        if (t[i] == s[j])
          dp.at(i + 1).at(j + 1) = dp.at(i).at(j) + dp.at(i + 1).at(j);
        else
          dp.at(i + 1).at(j + 1) = dp.at(i + 1).at(j);
      }
    }
    return dp.back().back();
  }
};
