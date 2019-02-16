class Solution {
public:
  string getPermutation(int n, int k) {
    std::string ret;
    for (int i = 1; i <= n; i++)
      ret += std::to_string(i);
    while (--k)
      std::next_permutation(ret.begin(), ret.end());
    return ret;
  }
};
