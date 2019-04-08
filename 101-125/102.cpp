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

public: // by @SOY
  vector<vector<int>> levelOrder(TreeNode *root) {
    std::queue<node *> que;
    std::vector<std::vector<int>> ret;
    if (root != nullptr) {
      que.push(root);
      while (!que.empty()) {
        int cur_level = que.size();
        std::vector<int> nums_on_level;
        for (int i = 0; i < cur_level; i++) {
          if (que.front()->left != nullptr)
            que.push(que.front()->left);
          if (que.front()->right != nullptr)
            que.push(que.front()->right);
          nums_on_level.push_back(que.front()->val);
          que.pop();
        }
        ret.push_back(nums_on_level);
      }
    }
    return ret;
  }
};
