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
  int max_val;
  int max_path_down(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = std::max(0, max_path_down(root->left));
    int right = std::max(0, max_path_down(root->right));
    max_val = std::max(max_val, left + right + root->val);
    return std::max(left, right) + root->val;
  }

public: // by @wei-bung
  int maxPathSum(TreeNode *root) {
    max_val = std::numeric_limits<int>::min();
    max_path_down(root);
    return max_val;
  }
};
