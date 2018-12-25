class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int ret, dis = pow(2, 30);
    if (nums.size() < 3)
      return ret;
    std::sort(nums.begin(), nums.end());
    bool first_flag = true;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (first_flag)
        first_flag = false;
      else if (nums.at(i) == nums.at(i - 1)) // skip duplicate
        continue;

      int lb = i + 1, hb = nums.size() - 1;
      while (lb < hb) { // double ptr
        int tmp = nums.at(i) + nums.at(lb) + nums.at(hb);
        if (tmp == target) {
          return target;
        } else if (tmp > target) {
          if (abs(target - tmp) < dis) {
            dis = abs(target - tmp);
            ret = tmp;
          }
          hb--;
        } else {
          if (abs(target - tmp) < dis) {
            dis = abs(target - tmp);
            ret = tmp;
          }
          lb++;
        }
      }
    }
    return ret;
  }
};
