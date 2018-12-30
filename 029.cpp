class Solution {
public:
  int divide(int dividend, int divisor) {
    int lb = std::numeric_limits<int>::lowest(),
        hb = std::numeric_limits<int>::max();
    if (dividend == hb && divisor == 1)
      return hb;
    else if (dividend == lb && divisor == -1)
      return hb;
    else if (dividend == hb && divisor == -1)
      return lb;
    else if (dividend == lb && divisor == 1)
      return lb;
    else
      return dividend / divisor;
  }
};
