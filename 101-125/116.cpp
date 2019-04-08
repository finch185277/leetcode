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
public: // by @ragepyre
  Node *connect(Node *root) {
    if (root != nullptr) {
      Node *pre = root, *cur = nullptr;
      while (pre->left != nullptr) {
        cur = pre;
        while (cur != nullptr) {
          cur->left->next = cur->right;
          if (cur->next != nullptr)
            cur->right->next = cur->next->left;
          cur = cur->next;
        }
        pre = pre->left;
      }
    }
    return root;
  }
};
