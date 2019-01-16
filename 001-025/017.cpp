class Solution {
public:
  inline std::vector<std::string> make_table() {
    std::vector<std::string> table{"*",   "*",   "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return table;
  }
  vector<string> letterCombinations(string digits) {
    std::vector<std::string> ret;
    int digits_len = digits.size();
    if (digits_len < 1)
      return ret;
    std::vector<std::string> table(make_table());
    ret.push_back("");
    for (int i = 0; i < digits_len; i++) {
      int num = digits[i] - '0';
      if (num >= 2 && num <= 9) {
        std::string str = table.at(num);
        std::vector<string> tmp;
        for (int j = 0; j < ret.size(); j++)
          for (int k = 0; k < str.size(); k++) {
            tmp.push_back(ret.at(j) + str[k]);
          }
        ret.swap(tmp); // ret = tmp
      }
    }
    return ret;
  }
};
