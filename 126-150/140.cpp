class Solution {
private:
  bool canBreak(std::string s, std::vector<std::string> &wordDict) {
    int n = s.size();
    std::set<std::string> dict;
    for (auto &w : wordDict)
      dict.insert(w);
    std::vector<bool> dp(n + 1, false);
    dp.front() = true;
    for (int i = 0; i < n; i++) {
      for (int j = i; j >= 0; j--) {
        std::string cur = s.substr(j, i - j + 1);
        if (dict.find(cur) != dict.end())
          dp.at(i + 1) = dp.at(i + 1) || dp.at(j);
        if (dp.at(i + 1))
          break;
      }
    }
    return dp.at(n);
  }

public: // by @golden_teeth @sohammehta
  std::vector<std::string> wordBreak(std::string s,
                                     std::vector<std::string> &wordDict) {
    int n = s.size();
    if (!canBreak(s, wordDict))
      return {};
    std::set<std::string> dict;
    for (auto &w : wordDict)
      dict.insert(w);
    std::vector<std::vector<std::string>> dp(n + 1);
    dp.front().push_back("");
    for (int i = 0; i < n; i++) {
      for (int j = i; j >= 0; j--) {
        std::string cur = s.substr(j, i - j + 1);
        if (dict.find(cur) != dict.end()) {
          for (std::string &str : dp.at(j)) {
            if (j == 0)
              dp.at(i + 1).push_back(cur);
            else
              dp.at(i + 1).push_back(str + " " + cur);
          }
        }
      }
    }
    return dp.back();
  }
};
