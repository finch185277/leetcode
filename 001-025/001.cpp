class Solution {
public:
  inline static bool cmp_pair(const std::pair<int, int> &lhs,
                              const std::pair<int, int> &rhs) {
    return lhs.second <= rhs.second;
  }
  inline vector<int> twoSum(vector<int> &nums, int target) {
    std::vector<std::pair<int, int>> pmap;
    for (int i = 0; i < nums.size(); i++) {
      std::pair<int, int> p(i, nums.at(i));
      pmap.push_back(p);
    }
    std::sort(pmap.begin(), pmap.end(), cmp_pair);
    int lb = 0, hb = nums.size() - 1;
    bool flag = true;
    while (flag) {
      if (pmap.at(lb).second + pmap.at(hb).second == target)
        flag = false;
      else if (pmap.at(lb).second + pmap.at(hb).second > target)
        hb--;
      else
        lb++;
    }
    std::vector<int> ret;
    ret.push_back(pmap.at(lb).first);
    ret.push_back(pmap.at(hb).first);
    return ret;
  }
};
