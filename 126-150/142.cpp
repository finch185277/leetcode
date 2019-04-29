/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by @ngcl
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;
    ListNode *slow = head, *fast = head, *entry = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        while (slow != entry) {
          slow = slow->next;
          entry = entry->next;
        }
        return entry;
      }
    }
    return nullptr;
  }
};
