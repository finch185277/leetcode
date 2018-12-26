class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    if (nums.size() < 3)
      return ret;
    std::sort(nums.begin(), nums.end());
    bool first_flag = true;
    for (int i = 0; i < nums.size() - 2; i++) {
      if (first_flag)
        first_flag = false;
      else if (nums.at(i) == nums.at(i - 1)) // skip duplicate
        continue;

      int lb = i + 1, hb = nums.size() - 1;
      while (lb < hb) { // double ptr
        int sum = nums.at(i) + nums.at(lb) + nums.at(hb);
        if (sum == 0) {
          std::vector<int> tmp;
          tmp.push_back(nums.at(i));
          tmp.push_back(nums.at(lb++));
          tmp.push_back(nums.at(hb--));
          if (ret.empty())
            ret.push_back(tmp);
          else if (tmp != ret.back()) // skip duplicate
            ret.push_back(tmp);
        } else if (sum > 0)
          hb--;
        else
          lb++;
      }
    }
    return ret;
  }
};
