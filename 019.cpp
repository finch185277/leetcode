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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *first = dummy, *second = dummy;
    for (int i = 1; i <= n + 1; i++) {
      first = first->next; // gap = n + 1
    }
    while (first != nullptr) { // first stop in nullptr,
      first = first->next;     // second stop one node before target,
      second = second->next;   // and n node between them
    }
    second->next = second->next->next;
    return dummy->next;
  }
};
