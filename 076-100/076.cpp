class Solution {
public: // by @zjh08177
  string minWindow(string s, string t) {
    std::vector<int> dict(128, 0);
    for (char c : t)
      dict.at(c)++;
    int counter = t.size(), begin = 0, end = 0, head = 0,
        dis = std::numeric_limits<int>::max();
    while (end < s.size()) {
      if (dict.at(s[end++])-- > 0) // in t
        counter--;
      while (counter == 0) { // valid
        if (end - begin < dis)
          dis = end - (head = begin);
        if (dict.at(s[begin++])++ == 0)
          counter++; // make it invalid
      }
    }
    return dis == std::numeric_limits<int>::max() ? "" : s.substr(head, dis);
  }
};
