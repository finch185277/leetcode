class Solution {
public: // by @yuruofeifei
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ret = {{}};
    int index = 0, size = 0;
    for (int i = 0; i < nums.size(); i++) {
      index = i >= 1 && nums.at(i) == nums.at(i - 1) ? size : 0;
      size = ret.size();
      for (int j = index; j < size; j++) {
        ret.at(j).push_back(nums.at(i));
        ret.push_back(ret.at(j));
        ret.at(j).pop_back();
      }
    }
    return ret;
  }
};
