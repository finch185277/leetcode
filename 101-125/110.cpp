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
  int dfs_height(node *root) {
    if (root == nullptr)
      return 0;
    int left_height = dfs_height(root->left);
    int right_height = dfs_height(root->right);
    if (left_height == -1 || right_height == -1 ||
        std::abs(left_height - right_height) > 1)
      return -1;
    else
      return std::max(left_height, right_height) + 1;
  }

public: // @benlong
  bool isBalanced(node *root) { return dfs_height(root) != -1; }
};
