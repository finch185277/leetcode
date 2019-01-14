class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    std::string ret;
    if (num1.size() > num2.size()) // length of num2 must bigger
      std::swap(num1, num2);
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    std::vector<std::vector<int>> table(
        num1.size(), std::vector<int>(num1.size() + num2.size(), 0));
    for (int i = 0; i < num1.size(); i++) {
      int carry = 0, sum = 0;
      for (int j = 0; j < num2.size(); j++) {
        sum = ((int)num1[i] - '0') * ((int)num2[j] - '0') + carry;
        carry = sum / 10;
        table.at(i).at(i + j) = sum % 10;
      }
      if (carry != 0)
        table.at(i).at(i + num2.size()) = carry;
    }
    int carry = 0;
    for (int i = 0; i < num1.size() + num2.size(); i++) {
      int sum = carry;
      for (std::vector<int> row : table)
        sum += row.at(i);
      carry = sum / 10;
      ret += std::to_string(sum % 10);
    }
    while (ret.back() == '0')
      ret.pop_back();
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};
