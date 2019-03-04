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
  inline void helper(TreeNode *root, std::vector<int> &ret) {
    if (root != nullptr) {
      if (root->left != nullptr)
        helper(root->left, ret);
      ret.push_back(root->val);
      if (root->right != nullptr)
        helper(root->right, ret);
    }
  }

public: // by Approach 1: Recursive Approach
  vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ret;
    helper(root, ret);
    return ret;
  }
};
