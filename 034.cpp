class Solution {
private: // Approach 2: Binary Search
  int extreme_insertion_index(std::vector<int> nums, int target, bool left) {
    int lb = 0, hb = nums.size();
    while (lb < hb) {
      int mid = (lb + hb) / 2;
      if (nums.at(mid) > target || (left && target == nums.at(mid)))
        hb = mid;
      else
        lb = mid + 1;
    }
    return lb;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    std::vector<int> target_range = {-1, -1};
    int left_idx = extreme_insertion_index(nums, target, true);
    if (left_idx == nums.size() || nums.at(left_idx) != target)
      return target_range;
    target_range.at(0) = left_idx;
    target_range.at(1) = extreme_insertion_index(nums, target, false) - 1;
    return target_range;
  }
};
