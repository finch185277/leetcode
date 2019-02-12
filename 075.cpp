class Solution {
public:
  void sortColors(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) { // front to back
      if (nums.at(i) == 0) {
        nums.erase(nums.begin() + i);
        nums.insert(nums.begin(), 0); // push front
      }
    }
    for (int i = nums.size() - 1; i >= 0; i--) { // back to front
      if (nums.at(i) == 2) {
        nums.erase(nums.begin() + i);
        nums.insert(nums.end(), 2); // push back
      }
    }
  }
};
