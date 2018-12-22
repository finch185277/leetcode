class Solution {
public:
  int expand_around_center(const std::string &s, const int left,
                           const int right) {
    int l(left), r(right);
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--;
      r++;
    }
    return r - l - 1;
  }
  string longestPalindrome(string s) {
    int slen = s.size();
    if (slen == 0)
      return "";
    int start = 0, end = 0;
    for (int i = 0; i < slen; i++) {
      int len1 = expand_around_center(s, i, i);     // a
      int len2 = expand_around_center(s, i, i + 1); // aa
      int len = std::max(len1, len2);
      if (len > end - start) {
        start = i - (len - 1) / 2;
        end = i + len / 2;
      }
    }
    return s.substr(start, end - start + 1);
  }
};
