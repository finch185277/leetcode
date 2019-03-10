class Solution {
public: // by @yu6
  int numDecodings(string s) {
    int p = 1, pp;
    for (int i = s.size() - 1; i >= 0; i--) {
      int cur = s[i] == '0' ? 0 : p;
      if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
        cur += pp;
      pp = p;
      p = cur;
    }
    return s.empty() ? 0 : p;
  }
};
