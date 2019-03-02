/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by Approach 2: Iterative Link Reversal.
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (head == nullptr)
      return nullptr;
    ListNode *cur = head, *pre = nullptr;
    while (m > 1) {
      pre = cur;
      cur = cur->next;
      m--;
      n--;
    }
    ListNode *con = pre, *tail = cur, *third = nullptr;
    while (n > 0) {
      third = cur->next;
      cur->next = pre;
      pre = cur;
      cur = third;
      n--;
    }
    if (con != nullptr)
      con->next = pre;
    else
      head = pre;
    tail->next = cur;
    return head;
  }
};
