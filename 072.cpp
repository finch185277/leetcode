class Solution {
public: // by @jianchao-li
  int minDistance(string word1, string word2) {
    // dp[i][j]: min operations to covert word1[0...i-1] to word2[0...j-1]
    std::vector<std::vector<int>> dp(word1.size() + 1,
                                     std::vector<int>(word2.size() + 1, 0));
    for (int i = 1; i <= word1.size(); i++)
      dp.at(i).at(0) = i;
    for (int j = 1; j <= word2.size(); j++)
      dp.at(0).at(j) = j;
    for (int i = 1; i <= word1.size(); i++) {
      for (int j = 1; j <= word2.size(); j++) {
        if (word1.at(i - 1) == word2.at(j - 1))
          dp.at(i).at(j) = dp.at(i - 1).at(j - 1);
        else
          dp.at(i).at(j) = std::min(
              dp.at(i - 1).at(j - 1) + 1, // replace or delete or insert
              std::min(dp.at(i - 1).at(j) + 1, dp.at(i).at(j - 1) + 1));
      }
    }
    return dp.back().back();
  }
};
