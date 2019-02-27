class Solution {
public: // by @yuyibestman
  vector<int> grayCode(int n) {
    std::vector<int> ret(1, 0);
    for (int i = 0; i < n; i++)
      for (int k = ret.size() - 1; k >= 0; k--)
        ret.push_back(ret.at(k) | 1 << i);
    return ret;
  }
};
