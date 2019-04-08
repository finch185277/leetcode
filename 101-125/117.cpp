/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public: // by @flashstone
  Node *connect(Node *root) {
    Node *head = nullptr, *pre = nullptr, *cur = root;
    while (cur != nullptr) {
      while (cur != nullptr) {
        if (cur->left != nullptr) {
          if (pre != nullptr)
            pre->next = cur->left;
          else
            head = cur->left;
          pre = cur->left;
        }
        if (cur->right != nullptr) {
          if (pre != nullptr)
            pre->next = cur->right;
          else
            head = cur->right;
          pre = cur->right;
        }
        cur = cur->next;
      }
      cur = head;
      head = nullptr;
      pre = nullptr;
    }
    return root;
  }
};
