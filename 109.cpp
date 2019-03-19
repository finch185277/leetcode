/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  void map_list_to_values(std::vector<int> &values, ListNode *head) {
    while (head != nullptr) {
      values.push_back(head->val);
      head = head->next;
    }
  }
  TreeNode *convert_list_to_BST(std::vector<int> &values, int left, int right) {
    if (left > right)
      return nullptr;
    int mid = (left + right) / 2;
    TreeNode *node = new TreeNode(values.at(mid));
    if (left == right)
      return node;
    node->left = convert_list_to_BST(values, left, mid - 1);
    node->right = convert_list_to_BST(values, mid + 1, right);
    return node;
  }

public: // by Approach 2: Recursion + Conversion to Array
  TreeNode *sortedListToBST(ListNode *head) {
    std::vector<int> values;
    map_list_to_values(values, head);
    return convert_list_to_BST(values, 0, values.size() - 1);
  }
};
