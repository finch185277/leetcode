class Solution {
public:
  bool isMatch(string text, string pattern) {
    std::vector<std::vector<bool>> dp(
        text.size() + 1, std::vector<bool>(pattern.size() + 1, false));

    dp.at(text.size()).at(pattern.size()) = true;
    for (int i = text.length(); i >= 0; i--) {
      for (int j = pattern.length() - 1; j >= 0; j--) {
        bool first_match =
            (i < text.length() && (pattern[j] == text[i] || pattern[j] == '.'));
        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
          dp.at(i).at(j) =
              dp.at(i).at(j + 2) || first_match && dp.at(i + 1).at(j);
        } else {
          dp.at(i).at(j) = first_match && dp.at(i + 1).at(j + 1);
        }
      }
    }
    return dp.at(0).at(0);
  }
};
