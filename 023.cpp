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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    std::vector<int> nums;
    for (ListNode *head : lists) {
      ListNode *cur = head;
      while (cur != nullptr) {
        nums.push_back(cur->val);
        cur = cur->next;
      }
    }
    std::sort(nums.begin(), nums.end());
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    for (int i : nums) {
      cur->next = new ListNode(i);
      cur = cur->next;
    }
    return dummy->next;
  }
};
