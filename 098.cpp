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
  bool isValidBST(node *root, node *min, node *max) {
    if (root == nullptr)
      return true;
    if (min != nullptr && root->val <= min->val ||
        max != nullptr && root->val >= max->val)
      return false;
    return isValidBST(root->left, min, root) &&
           isValidBST(root->right, root, max);
  }

public: // by @jaewoo
  bool isValidBST(TreeNode *root) { return isValidBST(root, nullptr, nullptr); }
};
