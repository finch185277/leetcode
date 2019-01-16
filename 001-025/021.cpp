/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *lhs = l1, *rhs = l2, *cur = dummy;
    while (lhs != nullptr || rhs != nullptr) {
      if (lhs == nullptr) {
        cur->next = new ListNode(rhs->val);
        cur = cur->next;
        rhs = rhs->next;
      } else if (rhs == nullptr) {
        cur->next = new ListNode(lhs->val);
        cur = cur->next;
        lhs = lhs->next;
      } else if (lhs->val < rhs->val) {
        cur->next = new ListNode(lhs->val);
        cur = cur->next;
        lhs = lhs->next;
      } else {
        cur->next = new ListNode(rhs->val);
        cur = cur->next;
        rhs = rhs->next;
      }
    }
    return dummy->next;
  }
};
