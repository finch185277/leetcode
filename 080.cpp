class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int cur = std::numeric_limits<int>::max(), freq = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (cur == nums.at(i)) {
        if (++freq > 2)
          nums.erase(nums.begin() + i--);
      } else {
        cur = nums.at(i);
        freq = 1;
      }
    }
    return nums.size();
  }
};
