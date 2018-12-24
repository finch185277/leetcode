class Solution {
public:
  int romanToInt(string s) {
    int ret = 0;
    s.push_back('I'); // for single word and i from 0 to len-1
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'I' && s[i + 1] == 'V') {
        ret += 4;
        i++;
      } else if (s[i] == 'I' && s[i + 1] == 'X') {
        ret += 9;
        i++;
      } else if (s[i] == 'I')
        ret += 1;
      else if (s[i] == 'V')
        ret += 5;
      else if (s[i] == 'X' && s[i + 1] == 'L') {
        ret += 40;
        i++;
      } else if (s[i] == 'X' && s[i + 1] == 'C') {
        ret += 90;
        i++;
      } else if (s[i] == 'X')
        ret += 10;
      else if (s[i] == 'L')
        ret += 50;
      else if (s[i] == 'C' && s[i + 1] == 'D') {
        ret += 400;
        i++;
      } else if (s[i] == 'C' && s[i + 1] == 'M') {
        ret += 900;
        i++;
      } else if (s[i] == 'C')
        ret += 100;
      else if (s[i] == 'D')
        ret += 500;
      else if (s[i] == 'M')
        ret += 1000;
    }
    return ret;
  }
};
