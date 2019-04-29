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
private:
  int sumNumbers(TreeNode *root, int start) {
    if (root == nullptr)
      return 0;
    if (root->left == nullptr && root->right == nullptr)
      return start * 10 + root->val;
    return sumNumbers(root->left, start * 10 + root->val) +
           sumNumbers(root->right, start * 10 + root->val);
  }

public: // by @pavel-shlyk
  int sumNumbers(TreeNode *root) { return sumNumbers(root, 0); }
};
