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
  node *helper(std::vector<int> &preorder, std::vector<int> &inorder,
               int prestart, int instart, int inend) {
    if (prestart > preorder.size() || instart > inend)
      return nullptr;
    node *root = new node(preorder.at(prestart));
    int inindex = 0;
    for (int i = instart; i <= inend; i++)
      if (inorder.at(i) == root->val)
        inindex = i;
    root->left = helper(preorder, inorder, prestart + 1, instart, inindex - 1);
    root->right = helper(preorder, inorder, prestart + inindex - instart + 1,
                         inindex + 1, inend);
    return root;
  }

public: // by @jiaming2
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return helper(preorder, inorder, 0, 0, inorder.size() - 1);
  }
};
