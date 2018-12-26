class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    std::vector<std::vector<int>> ret;
    if (nums.size() < 4)
      return ret;
    std::sort(nums.begin(), nums.end());
    bool first_flag = true;
    for (int i = 0; i < nums.size() - 3; i++) {
      if (first_flag)
        first_flag = false;
      else if (nums.at(i) == nums.at(i - 1)) // skip duplicate
        continue;
      bool second_flag = true;
      for (int j = i + 1; j < nums.size() - 2; j++) {
        if (second_flag)
          second_flag = false;
        else if (nums.at(j) == nums.at(j - 1)) // skip duplicate
          continue;
        int lb = j + 1, hb = nums.size() - 1;
        while (lb < hb) { // double ptr
          int sum = nums.at(i) + nums.at(j) + nums.at(lb) + nums.at(hb);
          if (sum == target) {
            std::vector<int> tmp;
            tmp.push_back(nums.at(i));
            tmp.push_back(nums.at(j));
            tmp.push_back(nums.at(lb++));
            tmp.push_back(nums.at(hb--));
            if (ret.empty())
              ret.push_back(tmp);
            else if (tmp != ret.back()) // skip duplicate
              ret.push_back(tmp);
          } else if (sum > target)
            hb--;
          else
            lb++;
        }
      }
    }
    return ret;
  }
};
