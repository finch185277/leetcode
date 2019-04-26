/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by @sbvictory
  ListNode *insertionSortList(ListNode *head) {
    if (head == nullptr)
      return head;
    ListNode *helper = new ListNode(0), *cur = head, *pre = helper,
             *next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      while (pre->next != nullptr && pre->next->val < cur->val)
        pre = pre->next;
      cur->next = pre->next;
      pre->next = cur;
      pre = helper;
      cur = next;
    }
    return helper->next;
  }
};
