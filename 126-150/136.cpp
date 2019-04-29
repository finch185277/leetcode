class Solution {
public: // by Approach 4: Bit Manipulation
  int singleNumber(std::vector<int> &nums) {
    int ret(0);
    for (int &i : nums)
      ret ^= i;
    return ret;
  }
};
