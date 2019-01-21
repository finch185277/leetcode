class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ret;
    do {
      ret.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));
    return ret;
  }
};
