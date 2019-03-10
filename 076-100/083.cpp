/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by Approach 1: Straight-Forward Approach
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->val == cur->next->val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }
    return head;
  }
};
