class Solution {
public: // Approach 3: Using Stack
  inline int longestValidParentheses(string s) {
    int ret = 0;
    std::stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        stk.push(i);
      else {
        stk.pop();
        if (stk.empty())
          stk.push(i);
        else
          ret = std::max(ret, i - stk.top());
      }
    }
    return ret;
  }
};
