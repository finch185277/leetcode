class Solution {
public:
  string countAndSay(int n) {
    if (n == 0)
      return "";
    std::string ret = "1"; // n = 1;
    while (--n) {
      std::string cur = "";
      for (int i = 0; i < ret.size(); i++) {
        int count = 1;
        while ((i + 1 < ret.size()) && (ret.at(i) == ret.at(i + 1))) {
          count++; // count the duplicate element length
          i++;
        }
        cur += std::to_string(count) + ret.at(i);
      }
      ret = cur;
    }
    return ret;
  }
};
