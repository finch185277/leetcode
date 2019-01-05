class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    std::vector<int> target_range(2, -1);
    if (!nums.empty() && target <= nums.back() && target >= nums.front()) {
      auto lb = std::lower_bound(nums.begin(), nums.end(), target),
           hb = std::upper_bound(nums.begin(), nums.end(), target);
      if (*lb == target)
        target_range.at(0) = lb - nums.begin();
      if (*(--hb) == target)
        target_range.at(1) = hb - nums.begin();
    }
    return target_range;
  }
};
