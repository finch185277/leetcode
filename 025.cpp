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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(0), *pre = dummy, *cur = pre;
    dummy->next = head;
    int num = 0;
    while (cur = cur->next)
      num++;
    while (num >= k) {
      cur = pre->next;
      for (int i = 1; i < k; i++) {
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
      }
      pre = cur;
      num -= k;
    }
    return dummy->next;
  }
};
