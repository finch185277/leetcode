class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int lb = 0, hb = nums.size() - 1;
    if (target < nums.front())
      return 0;
    else if (target > nums.back())
      return nums.size();
    while (lb < hb) {
      int mid = (lb + hb) / 2;
      if (nums.at(mid) == target)
        return mid;
      else if (nums.at(mid) < target)
        lb = mid + 1;
      else
        hb = mid;
    }
    return hb;
  }
};
