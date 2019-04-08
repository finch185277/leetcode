/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  using node = TreeNode;

private:
  void travel(std::vector<std::vector<int>> &ret, node *cur, int level) {
    if (cur == nullptr)
      return;
    if (ret.size() <= level)
      ret.emplace_back();
    if (level % 2 == 0)
      ret.at(level).push_back(cur->val);
    else
      ret.at(level).insert(ret.at(level).begin(), cur->val);
    travel(ret, cur->left, level + 1);
    travel(ret, cur->right, level + 1);
  }

public: // by @awaylu
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ret;
    travel(ret, root, 0);
    return ret;
  }
};
