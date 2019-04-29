class Solution {
private:
  bool is_palindrome(std::string &s, int l, int r) {
    while (l <= r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
  void back_track(std::vector<std::vector<std::string>> &ret,
                  std::vector<std::string> &cur, std::string &s, int idx) {
    if (idx == s.size())
      ret.push_back(cur);
    for (int i = idx; i < s.size(); i++) {
      if (is_palindrome(s, idx, i)) {
        cur.push_back(s.substr(idx, i - idx + 1));
        back_track(ret, cur, s, i + 1);
        cur.pop_back();
      }
    }
  }

public: // by @zhangyu917
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> ret;
    std::vector<std::string> cur;
    back_track(ret, cur, s, 0);
    return ret;
  }
};
