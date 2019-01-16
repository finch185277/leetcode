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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *p = l1, *q = l2, *cur = head;
    int carry = 0;
    while (p != nullptr || q != nullptr) {
      int x = (p != nullptr) ? p->val : 0;
      int y = (q != nullptr) ? q->val : 0;
      int sum = carry + x + y;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (p != nullptr)
        p = p->next;
      if (q != nullptr)
        q = q->next;
    }
    if (carry)
      cur->next = new ListNode(carry);
    return head->next;
  }
};
