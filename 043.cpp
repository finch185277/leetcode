class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    std::string ret;
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    std::vector<int> table(num1.size() + num2.size(), 0);
    for (int i = 0; i < num1.size(); i++) {
      int carry = 0, sum = 0;
      for (int j = 0; j < num2.size(); j++) {
        sum = ((int)num1[i] - '0') * ((int)num2[j] - '0') + carry;
        carry = sum / 10;
        table.at(i + j) += sum % 10;
      }
      if (carry != 0)
        table.at(i + num2.size()) += carry;
    }
    int carry = 0;
    for (int i = 0; i < num1.size() + num2.size(); i++) {
      int sum = carry;
      sum += table.at(i);
      carry = sum / 10;
      ret += std::to_string(sum % 10);
    }
    while (ret.back() == '0')
      ret.pop_back();
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};
