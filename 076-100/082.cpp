/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by @snowfish
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(0), *pre = dummy, *cur = head;
    dummy->next = head;
    while (cur != nullptr) {
      while (cur->next != nullptr && cur->val == cur->next->val)
        cur = cur->next;
      if (pre->next == cur)
        pre = pre->next;
      else
        pre->next = cur->next;
      cur = cur->next;
    }
    return dummy->next;
  }
};
