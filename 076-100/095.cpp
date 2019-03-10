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
  std::vector<node *> gen_trees(int start, int end) {
    std::vector<node *> ret;
    if (start > end)
      ret.push_back(nullptr);
    else if (start == end)
      ret.push_back(new node(start));
    else {
      std::vector<node *> left, right;
      for (int i = start; i <= end; i++) {
        left = gen_trees(start, i - 1);
        right = gen_trees(i + 1, end);
        for (node *lnode : left) {
          for (node *rnode : right) {
            node *root = new node(i);
            root->left = lnode;
            root->right = rnode;
            ret.push_back(root);
          }
        }
      }
    }
    return ret;
  }

public: // by @Jayanta
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0)
      return {};
    else
      return gen_trees(1, n);
  }
};
