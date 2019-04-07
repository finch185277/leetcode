class Solution {
public: // by Approach 3: HashSet and Intelligent Sequence Building
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> num_set;
    for (int num : nums)
      num_set.insert(num);
    int longest_streak = 0;
    for (int num : num_set) {
      if (num_set.find(num - 1) == num_set.end()) {
        int cur_num = num;
        int cur_streak = 1;
        while (num_set.find(cur_num + 1) != num_set.end()) {
          cur_num += 1;
          cur_streak += 1;
        }
        longest_streak = std::max(longest_streak, cur_streak);
      }
    }
    return longest_streak;
  }
};
