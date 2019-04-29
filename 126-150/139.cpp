class Solution {
public: // by @paul7
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    if (wordDict.empty())
      return false;
    std::vector<bool> dp(s.size() + 1, false);
    dp.front() = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp.at(j)) {
          std::string word = s.substr(j, i - j);
          if (std::find(wordDict.begin(), wordDict.end(), word) !=
              wordDict.end()) {
            dp.at(i) = true;
            break;
          }
        }
      }
    }
    return dp.back();
  }
};
