class Solution {
public:
  int lengthOfLastWord(string s) {
    int count = 0;
    bool counting = false;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == ' ' && !counting)
        continue; // not yet to count
      else if (s[i] != ' ' && !counting) {
        counting = true; // start to count
        count++;
      } else if (s[i] != ' ' && counting)
        count++; // during counting
      else if (s[i] == ' ' && counting)
        break; // stop point when counting
    }
    return count;
  }
};
