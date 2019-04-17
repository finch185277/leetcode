/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public: // @satyakam
  Node *copyRandomList(Node *head) {
    Node *dummy, *cur, *after;
    if (head == nullptr)
      return nullptr;
    for (cur = head; cur != nullptr; cur = cur->next) {
      after = new Node(cur->val);
      after->next = cur->random;
      cur->random = after;
    }
    dummy = head->random;
    for (cur = head; cur != nullptr; cur = cur->next) {
      after = cur->random;
      after->random = after->next ? after->next->random : nullptr;
    }
    for (cur = head; cur != nullptr; cur = cur->next) {
      after = cur->random;
      cur->random = after->next;
      after->next = cur->next ? cur->next->random : nullptr;
    }
    return dummy;
  }
};
