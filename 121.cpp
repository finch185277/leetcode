class Solution {
public: // by Approach 2: One Pass
  int maxProfit(std::vector<int> &prices) {
    int min = std::numeric_limits<int>::max(), ret = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices.at(i) < min)
        min = prices.at(i);
      else if (prices.at(i) - min > ret)
        ret = prices.at(i) - min;
    }
    return ret;
  }
};
