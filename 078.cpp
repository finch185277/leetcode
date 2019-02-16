class Solution {
private:
  void make_subsets(const std::vector<int> &nums, int start,
                    std::vector<int> &sub,
                    std::vector<std::vector<int>> &subs) {
    subs.push_back(sub);
    for (int i = start; i < nums.size(); i++) {
      sub.push_back(nums.at(i));
      make_subsets(nums, i + 1, sub, subs);
      sub.pop_back();
    }
  }

public: // by @jianchao-li
  vector<vector<int>> subsets(vector<int> &nums) {
    std::vector<int> sub;
    std::vector<std::vector<int>> subs;
    make_subsets(nums, 0, sub, subs);
    return subs;
  }
};
