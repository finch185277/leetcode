class Solution {
public: // by @liaison
  int numTrees(int n) {
    std::vector<int> tree_num(n + 1);
    tree_num.at(0) = tree_num.at(1) = 1;
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= i; j++)
        tree_num.at(i) += tree_num.at(i - j) * tree_num.at(j - 1);
    return tree_num.at(n);
  }
};
