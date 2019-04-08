class Solution {
public: // by Approach 2: One Pass
  int maxProfit(std::vector<int> &prices) {
    int min = std::numeric_limits<int>::max(), ret = 0;
    for (int cur : prices) {
      if (cur < min)
        min = cur;
      else if (cur - min > ret)
        ret = cur - min;
    }
    return ret;
  }
};
