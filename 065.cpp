class Solution {
private:
  inline std::string trim_string(const std::string &str) {
    int l = 0, r = str.size() - 1;
    for (; l < str.size(); l++)
      if (str[l] != ' ')
        break;
    for (; r >= 0; r--)
      if (str[r] != ' ')
        break;
    return str.substr(l, r - l + 1);
  }

public: // by @balint
  bool isNumber(string s) {
    s = trim_string(s);
    bool e_flag = false, point_flag = false, start_flag = false,
         need_num_after_e = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        start_flag = true;
        need_num_after_e = false;
      } else if (s[i] == '.') {
        if (e_flag || point_flag)
          return false;
        point_flag = true;
      } else if (s[i] == 'e') {
        if (e_flag || !start_flag)
          return false;
        e_flag = true;
        need_num_after_e = true;
      } else if (s[i] == '-' || s[i] == '+') {
        if (i != 0 && s[i - 1] != 'e')
          return false;
      } else
        return false;
    }
    return start_flag && !need_num_after_e;
  }
};
