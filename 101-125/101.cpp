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
  bool is_mirror(node *lhs, node *rhs) {
    if (lhs == nullptr && rhs == nullptr)
      return true;
    if (lhs == nullptr || rhs == nullptr)
      return false;
    return lhs->val == rhs->val && is_mirror(lhs->left, rhs->right) &&
           is_mirror(lhs->right, rhs->left);
  }

public: // by Approach 1: Recursive
  bool isSymmetric(TreeNode *root) { return is_mirror(root, root); }
};
