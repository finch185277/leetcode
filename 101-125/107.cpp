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
  void levelOrderBottom(std::vector<std::vector<int>> &ret, node *root,
                        int level) {
    if (root == nullptr)
      return;
    if (level >= ret.size())
      ret.insert(ret.begin(), std::vector<int>());
    levelOrderBottom(ret, root->left, level + 1);
    levelOrderBottom(ret, root->right, level + 1);
    ret.at(ret.size() - level - 1).push_back(root->val);
  }

public: // by @SOY
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int>> ret;
    levelOrderBottom(ret, root, 0);
    return ret;
  }
};
