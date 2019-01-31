/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // by @dong.wang.1694
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) // empty list
      return nullptr;
    int len = 1;
    ListNode *dummy = head, *tail = head;
    while (tail->next) { // find the length
      tail = tail->next;
      len++;
    }
    tail->next = head; // make the circle
    for (int i = 0; i < len - k % len; i++)
      tail = tail->next;  // move tail to new list's tail
    dummy = tail->next;   // make the dummy be head of new list
    tail->next = nullptr; // cut the circle
    return dummy;
  }
};
