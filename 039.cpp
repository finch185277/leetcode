class Solution {
private:
  void combinate(std::vector<std::vector<int>> &ret, std::vector<int> &plan,
                 std::vector<int> &candidates, int target) {
    if (target == 0) { // save current plan
      ret.push_back(plan);
    } else if (target > 0) {
      for (int cur : candidates) {
        if (cur >= plan.back()) { // skip the used choice,
          plan.push_back(cur);    // and start from bigger number
          combinate(ret, plan, candidates, target - cur); // DFS the next degree
          plan.pop_back();
        }
      }
    } // else if (target < 0) return
    return;
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    std::vector<std::vector<int>> ret;
    for (int cur : candidates) { // DFS from root to every possible choice
      std::vector<int> plan;
      plan.push_back(cur);
      combinate(ret, plan, candidates, target - cur); // DFS
    }
    return ret;
  }
};
