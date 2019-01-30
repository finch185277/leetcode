class Solution {
public:
  string getPermutation(int n, int k) {
    std::vector<int> vec(n);
    std::string ret;
    for (int i = 0; i < n; i++)
      vec.at(i) = i + 1;
    while (--k)
      std::next_permutation(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
      ret.push_back(vec.at(i) + '0');
    return ret;
  }
};
