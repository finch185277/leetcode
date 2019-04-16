class Solution {
public: // by @againest1
  int singleNumber(std::vector<int> &nums) {
    int ones(0), twos(0);
    for (int &i : nums) {
      ones ^= i & ~twos;
      twos ^= i & ~ones;
    }
    return ones;
  }
};
