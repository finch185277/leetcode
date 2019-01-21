class Solution {
public: // by @jianchao-li
  int jump(vector<int> &nums) {
    int step = 0, start = 0, end = 0;
    while (end < nums.size() - 1) {
      step++;
      int maxend = end + 1;
      for (int i = start; i <= end; i++) {
        if (i + nums.at(i) >= nums.size() - 1)
          return step;
        maxend = std::max(maxend, i + nums.at(i));
      }
      start = end + 1;
      end = maxend;
    }
    return step;
  }
};
