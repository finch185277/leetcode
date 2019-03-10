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
  node *first, *second, *pre = new node(std::numeric_limits<int>::min());
  void traverse(node *root) {
    if (root == nullptr)
      return;
    traverse(root->left);
    if (first == nullptr && pre->val >= root->val)
      first = pre;
    if (first != nullptr && pre->val >= root->val)
      second = root;
    pre = root;
    traverse(root->right);
  }

public: // by @qwl5004
  void recoverTree(TreeNode *root) {
    traverse(root);
    std::swap(first->val, second->val);
  }
};
