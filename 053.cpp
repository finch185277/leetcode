class Solution {
public: // by @FujiwaranoSai
  int maxSubArray(vector<int> &nums) {
    std::vector<int> dp(nums.size()); // dp.at(i) is maxsum contain ith element,
    dp.at(0) = nums.at(0);            // and which is local optimal solution.
    int max = dp.at(0);               // max is global optimal solution.

    for (int i = 1; i < nums.size(); i++) {
      dp.at(i) = nums.at(i) + (dp.at(i - 1) > 0 ? dp.at(i - 1) : 0);
      max = std::max(max, dp.at(i));
    }

    return max;
  }
};
