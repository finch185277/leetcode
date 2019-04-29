/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by @wanqing
  void reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return;
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *pre_mid = slow, *pre_cur = slow->next;
    while (pre_cur->next != nullptr) {
      ListNode *cur = pre_cur->next;
      pre_cur->next = cur->next;
      cur->next = pre_mid->next;
      pre_mid->next = cur;
    }
    slow = head;
    fast = pre_mid->next;
    while (slow != pre_mid) {
      pre_mid->next = fast->next;
      fast->next = slow->next;
      slow->next = fast;
      slow = fast->next;
      fast = pre_mid->next;
    }
  }
};
