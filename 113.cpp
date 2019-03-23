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
  void find_path(std::vector<std::vector<int>> &paths, std::vector<int> &path,
                 TreeNode *node, int sum) {
    if (node == nullptr)
      return;
    path.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr && sum == node->val)
      paths.push_back(path);
    find_path(paths, path, node->left, sum - node->val);
    find_path(paths, path, node->right, sum - node->val);
    path.pop_back();
  }

public: // by @jianchao-li
  std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
    find_path(paths, path, root, sum);
    return paths;
  }
};
