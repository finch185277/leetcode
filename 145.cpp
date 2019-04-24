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
  void postorder(TreeNode *root, std::vector<int> &nodes) {
    if (root == nullptr)
      return;
    postorder(root->left, nodes);
    postorder(root->right, nodes);
    nodes.push_back(root->val);
  }

public: // by @jianchao-li
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> nodes;
    postorder(root, nodes);
    return nodes;
  }
};
