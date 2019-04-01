class Solution {
public: // by @tian.xia.568
  int maxProfit(std::vector<int> &prices) {
    int ret = 0;
    for (int i = 1; i < prices.size(); i++)
      ret += max(0, prices.at(i) - prices.at(i - 1));
    return ret;
  }
};
