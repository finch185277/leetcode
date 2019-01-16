class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    std::string ret;
    std::vector<std::vector<char>> trans_pat(numRows);
    std::vector<std::string> split_str;
    int split_str_len = 2 * numRows - 2;
    int str_len = s.size(), recur_idx = 0;
    while (recur_idx < str_len) {
      if (recur_idx + split_str_len - 1 < str_len) {
        std::string tmp = s.substr(recur_idx, split_str_len);
        split_str.push_back(tmp);
        recur_idx += split_str_len;
      } else {
        int tmp_len = str_len - recur_idx;
        std::string tmp = s.substr(recur_idx, tmp_len);
        split_str.push_back(tmp);
        break;
      }
    }
    for (std::string ss : split_str) {
      int ss_idx = 0, tp_idx = -1;
      bool stop_flag = false;
      for (; ss_idx < numRows; ss_idx++) {
        if (ss_idx < ss.size()) {
          trans_pat.at(++tp_idx).push_back(ss[ss_idx]);
        } else {
          stop_flag = true;
          break;
        }
      }
      if (!stop_flag) {
        for (; ss_idx < 2 * numRows - 2; ss_idx++) {
          if (ss_idx < ss.size()) {
            trans_pat.at(--tp_idx).push_back(ss[ss_idx]);
          } else
            break;
        }
      }
    }
    for (int i = 0; i < numRows; i++) {
      for (char c : trans_pat.at(i)) {
        ret.push_back(c);
      }
    }
    return ret;
  }
};
