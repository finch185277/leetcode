class Solution {
public:
  bool find_element(const int _t, const vector<int> &_q) {
    return std::find(_q.begin(), _q.end(), _t) != _q.end();
  }
  int lengthOfLongestSubstring(string s) {
    std::vector<int> q;
    int max_len = 0;
    for (int i = 0; i < s.size(); i++) {
      if (!find_element((int)s[i], q)) {
        q.push_back((int)s[i]);
      } else {
        while (q.front() != s[i]) {
          q.erase(q.begin());
        }
        q.erase(q.begin());
        q.push_back((int)s[i]);
      }
      max_len = std::max(max_len, (int)q.size());
    }
    return max_len;
  }
};
