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
public: // by @caiqi8877
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int lhs = minDepth(root->left), rhs = minDepth(root->right);
    if (lhs == 0 || rhs == 0)
      return lhs + rhs + 1;
    else
      return std::min(lhs, rhs) + 1;
  }
};
