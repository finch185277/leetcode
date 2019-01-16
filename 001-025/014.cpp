class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";
    int min_str_len = pow(2, 30);
    for (std::string str : strs) {
      min_str_len = std::min(min_str_len, (int)str.size());
    }
    std::string ret;
    for (int i = 0; i < min_str_len; i++) {
      char tmp = strs.at(0)[i];
      bool same_char_flag = true;
      for (std::string str : strs) {
        if (str[i] != tmp) {
          same_char_flag = false;
          break;
        }
      }
      if (same_char_flag)
        ret.push_back(tmp);
      else
        break;
    }
    return ret;
  }
};
