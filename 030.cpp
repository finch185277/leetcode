class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    std::vector<int> ret;
    if (s.empty() || words.empty())
      return ret;
    std::sort(words.begin(), words.end());
    do {
      std::string target;
      for (std::string w : words)
        target += w;
      int target_len = target.size();
      for (int i = 0; i < s.size() - target_len + 1; i++) {
        if (s.substr(i, target_len) == target)
          ret.push_back(i);
      }
    } while (std::next_permutation(words.begin(), words.end()));
    return ret;
  }
};
