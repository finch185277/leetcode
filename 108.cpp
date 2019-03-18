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
  node *sortedArrayToBST(std::vector<int> &nums, int lb, int hb) {
    if (lb > hb)
      return nullptr;
    int mid = (lb + hb) / 2;
    node *root = new node(nums.at(mid));
    root->left = sortedArrayToBST(nums, lb, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, hb);
    return root;
  }

public: // by @jiaming2
  node *sortedArrayToBST(std::vector<int> &nums) {
    if (nums.empty())
      return nullptr;
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }
};
