/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  inline ListNode *merge_list(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0), *cur = dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1 != nullptr)
      cur->next = l1;
    if (l2 != nullptr)
      cur->next = l2;
    return dummy->next;
  }

public: // by @jeantimex
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *pre = nullptr, *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    pre->next = nullptr;
    ListNode *l1 = sortList(head), *l2 = sortList(slow);
    return merge_list(l1, l2);
  }
};
