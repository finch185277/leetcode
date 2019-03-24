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
  TreeNode *pre = nullptr;

public: // by @tusizi
  void flatten(TreeNode *root) {
    if (root == nullptr)
      return;
    flatten(root->right);
    flatten(root->left);
    root->right = pre;
    root->left = nullptr;
    pre = root;
  }
};
