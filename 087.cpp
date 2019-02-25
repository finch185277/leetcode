class Solution {
public: // @raychan
  bool isScramble(string s1, string s2) {
    if (s1 == s2)
      return true;
    int len = s1.size();
    std::vector<int> count(26, 0);
    for (int i = 0; i < len; i++) {
      count.at(s1.at(i) - 'a')++;
      count.at(s2.at(i) - 'a')--;
    }
    for (int i : count)
      if (i != 0)
        return false;
    for (int i = 1; i < len; i++) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i)))
        return true;
      if (isScramble(s1.substr(0, i), s2.substr(len - i)) &&
          isScramble(s1.substr(i), s2.substr(0, len - i)))
        return true;
    }
    return false;
  }
};
