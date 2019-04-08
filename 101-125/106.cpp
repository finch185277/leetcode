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
  node *buildTree(std::vector<int> &inorder, std::vector<int> &postorder,
                  int is, int ie, int ps, int pe) {
    if (is > ie || ps > pe)
      return nullptr;
    node *root = new node(postorder.at(pe));
    int pos;
    for (int i = is; i <= ie; i++) {
      if (inorder.at(i) == root->val) {
        pos = i;
        break;
      }
    }
    root->left =
        buildTree(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
    root->right =
        buildTree(inorder, postorder, pos + 1, ie, pe + pos - ie, pe - 1);
    return root;
  }

public: // by @zxyperfect
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty() || postorder.empty() ||
        inorder.size() != postorder.size())
      return nullptr;
    return buildTree(inorder, postorder, 0, inorder.size() - 1, 0,
                     postorder.size() - 1);
  }
};
