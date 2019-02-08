class Solution {
public:
  int climbStairs(int n) {
    std::vector<int> dp;
    dp.push_back(1); // s(0) = 1
    dp.push_back(1); // s(1) = 1
    if (n < 2)
      return dp.at(n);
    else // s(n) = s(n-2) + s(n-1) for n >= 2
      for (int i = 2; i <= n; i++)
        dp.push_back(dp.at(i - 2) + dp.at(i - 1));
    return dp.at(n);
  }
};
