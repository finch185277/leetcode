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
public: // by @pavel-shlyk
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ret;
    std::stack<TreeNode *> rights;
    while (root != nullptr) {
      ret.push_back(root->val);
      if (root->right != nullptr)
        rights.push(root->right);
      root = root->left;
      if (root == nullptr && !rights.empty()) {
        root = rights.top();
        rights.pop();
      }
    }
    return ret;
  }
};
