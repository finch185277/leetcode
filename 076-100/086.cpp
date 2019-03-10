/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by Approach 1: Two Pointer Approach
  ListNode *partition(ListNode *head, int x) {
    ListNode *before_head = new ListNode(0), *before = before_head,
             *after_head = new ListNode(0), *after = after_head;
    while (head != nullptr) {
      if (head->val < x) {
        before->next = head;
        before = before->next;
      } else {
        after->next = head;
        after = after->next;
      }
      head = head->next;
    }
    before->next = after_head->next;
    after->next = nullptr;
    return before_head->next;
  }
};
