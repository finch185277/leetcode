class Solution {
private:
  void combinate(std::vector<std::vector<int>> &ret, std::vector<int> &plan,
                 std::vector<int> &candidates, int target) {
    if (target == 0) { // save current plan
      if (ret.empty() || std::find(ret.begin(), ret.end(), plan) == ret.end())
        ret.push_back(plan); // push the unique plan
    } else if (target > 0) {
      std::vector<int> recur(candidates);
      recur.erase(std::find(recur.begin(), recur.end(), plan.back()));
      for (int cur : recur) {
        if (cur >= plan.back()) { // skip the used choice,
          plan.push_back(cur);    // and start from bigger number
          combinate(ret, plan, recur, target - cur); // DFS the next degree
          plan.pop_back();
        }
      }
    } // else if (target < 0) return
    return;
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ret;
    for (int cur : candidates) { // DFS from root to every possible choice
      if (ret.empty() || cur != ret.back().front()) { // skip the same root
        std::vector<int> plan;
        plan.push_back(cur);
        combinate(ret, plan, candidates, target - cur); // DFS
      }
    }
    return ret;
  }
};
