class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    if (digits.empty())
      return {1};
    int idx = digits.size() - 1;
    digits.at(idx)++;
    while (idx >= 0) {
      if (digits.at(idx) > 9) {
        digits.at(idx) %= 10;
        idx--;
        if (idx == -1)
          digits.insert(digits.begin(), 1);
        else
          digits.at(idx)++;
      } else
        break;
    }
    return digits;
  }
};
