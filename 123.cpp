class Solution {
public: // by @weijiac
  int maxProfit(std::vector<int> &prices) {
    int hold1 = std::numeric_limits<int>::min(),
        hold2 = std::numeric_limits<int>::min();
    int release1 = 0, release2 = 0;
    for (int cur : prices) {
      release2 = std::max(release2, hold2 + cur);
      hold2 = std::max(hold2, release1 - cur);
      release1 = std::max(release1, hold1 + cur);
      hold1 = std::max(hold1, -cur);
    }
    return release2;
  }
};
