class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty())
      return 0;
    else {
      int i = 0; // current idx for new range
      for (int j = 1; j < nums.size(); j++) {
        if (nums.at(i) != nums.at(j))
          nums.at(++i) = nums.at(j);
      }
      return i + 1;
      // return "len" should include from nums
      // ex. 3 3 4 4 4 6 7 7
      // ==> 3 4 6 7 4 6 7 7
      // => (3 4 6 7), return len = 4
    }
  }
};
