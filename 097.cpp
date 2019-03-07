class Solution {
public: // by Approach 4: Using 1D Dynamic Programming
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != s1.size() + s2.size())
      return false;
    std::vector<bool> dp(s2.size() + 1);
    for (int i = 0; i <= s1.size(); i++) {
      for (int j = 0; j <= s2.size(); j++) {
        if (i == 0 && j == 0)
          dp.at(j) = true;
        else if (i == 0)
          dp.at(j) = dp.at(j - 1) && s2[j - 1] == s3[i + j - 1];
        else if (j == 0)
          dp.at(j) = dp.at(j) && s1[i - 1] == s3[i + j - 1];
        else
          dp.at(j) = (dp.at(j) && s1[i - 1] == s3[i + j - 1] ||
                      dp.at(j - 1) && s2[j - 1] == s3[i + j - 1]);
      }
    }
    return dp.back();
  }
};
