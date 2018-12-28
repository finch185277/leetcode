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
  ListNode *swapPairs(ListNode *head) {
    bool flag = true;
    ListNode *dummy = new ListNode(0);
    ListNode *cur = head, *recur = dummy;
    while (cur != nullptr) {
      if (flag) { // cur in odd position
        if (cur->next != nullptr)
          std::swap(cur->val, cur->next->val);
        flag = false;
      } else
        flag = true;
      recur->next = new ListNode(cur->val);
      cur = cur->next;
      recur = recur->next;
    }
    return dummy->next;
  }
};
