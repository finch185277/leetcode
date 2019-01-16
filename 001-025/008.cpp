class Solution {
public:
  inline bool check_valid_char(const char &c) {
    if (c == ' ')
      return true;
    else if (c == '-' || c == '+')
      return true;
    else if (c >= '0' && c <= '9')
      return true;
    else
      return false;
  }
  int myAtoi(const std::string &str) { // pro_flag: processing "get num"
    bool pro_flag = false, neg_flag = false;
    int lb = pow(-2, 31), ub = pow(2, 31) - 1;
    double ret = 0;
    std::vector<int> num_vec;
    for (int i = 0; i < str.size(); i++) {
      char c = str[i];
      if (!pro_flag) {
        if (!check_valid_char(c))
          return 0;
        else {
          if (c == ' ')
            continue;
          else if (c == '+')
            pro_flag = true;
          else if (c == '-') {
            neg_flag = true;
            pro_flag = true;
          } else if (c >= '0' && c <= '9') {
            num_vec.push_back(c - '0');
            pro_flag = true;
          }
        }
      } else {
        if (c >= '0' && c <= '9') {
          num_vec.push_back(c - '0');
        } else
          break;
      }
    }
    for (int i = 0; i < num_vec.size(); i++) {
      ret += num_vec.at(i);
      ret *= 10;
    }
    ret /= 10;

    if (neg_flag)
      ret = -ret;

    if (ret < lb)
      return lb;
    else if (ret > ub)
      return ub;
    else
      return ret;
  }
};
