class Solution {
public:
  string addBinary(string a, string b) {
    std::string ret;
    if (a.size() > b.size())
      std::swap(a, b);                     // must size of b > a
    a.insert(0, b.size() - a.size(), '0'); // fill the empty position
    int carry = 0;                         // use int to operate
    for (int i = a.size() - 1; i >= 0; i--) {
      char sum = (a[i] - '0') + (b[i] - '0') + carry;
      if (sum >= 2) {
        sum -= 2;
        carry = 1;
      } else {
        carry = 0;
      }
      ret.insert(0, 1, '0' + sum); // push the (char)sum to head
    }
    if (carry == 1)
      ret.insert(0, 1, '1');
    return ret;
  }
};
