class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lb = 0, hb = nums.size() - 1;
    while (lb <= hb) {
      int mid = (lb + hb) / 2;
      if (nums.at(mid) == target)
        return mid;
      if (nums.at(mid) >= nums.at(lb)) {
        if (nums.at(lb) <= target && target < nums.at(mid))
          hb = mid - 1;
        else
          lb = mid + 1;
      } else {
        if (nums.at(mid) < target && target <= nums.at(hb))
          lb = mid + 1;
        else
          hb = mid - 1;
      }
    }
    return -1;
  }
};
