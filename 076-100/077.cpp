class Solution {
private:
  void gen_combinations(const int n, const int k, const int idx,
                        std::vector<int> &chosen,
                        std::vector<std::vector<int>> &combs) {
    if (chosen.size() == k) {
      combs.push_back(chosen);
      return;
    }
    for (int i = idx; i <= n; i++) {
      chosen.push_back(i);
      gen_combinations(n, k, i + 1, chosen, combs);
      chosen.pop_back();
    }
  }

public: // by @nangao
  vector<vector<int>> combine(int n, int k) {
    std::vector<int> chosen;
    std::vector<std::vector<int>> combs;
    gen_combinations(n, k, 1, chosen, combs);
    return combs;
  }
};
