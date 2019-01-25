class Solution {
public:
  int canJump(vector<int> &nums) {
    int i = 0; // if i bigger then reach, means this i th cannot be reached
    for (int reach = 0; i < nums.size() && i <= reach; i++)
      reach = std::max(reach, i + nums.at(i));
    return i == nums.size(); // yes, means the last position is reachable
  }
};
