class Solution {
public: // by @makuiyu
  string addBinary(string a, string b) {
    std::string ret;
    int i = a.size() - 1, j = b.size() - 1, carry = 0; // use int to operate
    while (i >= 0 || j >= 0 || carry == 1) {
      carry += i >= 0 ? (a[i--] - '0') : 0;
      carry += j >= 0 ? (b[j--] - '0') : 0;
      ret = char(carry % 2 + '0') + ret; // push the (char)sum to head
      carry /= 2;
    }
    return ret;
  }
};
