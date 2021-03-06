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
    auto cmp_node = [](const ListNode *lhs, const ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp_node)>
        pq(cmp_node);
    for (ListNode *head : lists) {
      if (head != nullptr)
        pq.push(head);
    }
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    while (!pq.empty()) {
      cur->next = new ListNode(pq.top()->val);
      cur = cur->next;
      if (pq.top()->next != nullptr)
        pq.push(pq.top()->next);
      pq.pop();
    }
    return dummy->next;
  }
};
