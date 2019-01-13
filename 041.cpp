class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    std::unordered_map<int, int> table;
    for (int i : nums) {
      if (i > 0)
        table[i]++;
    }
    int missing_num = 1; // search positive number from lowest to max integer
    for (; missing_num <= std::numeric_limits<int>::max(); missing_num++) {
      if (table.find(missing_num) == table.end())
        break;
    }
    return missing_num;
  }
};
