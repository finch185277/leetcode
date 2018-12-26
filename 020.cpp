class Solution {
public:
  bool isValid(string s) {
    std::stack<char> match_stack;
    for (int i = 0; i < s.size(); i++) {
      if (match_stack.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{')
        match_stack.push(s[i]);
      else if (s[i] == ')') {
        if (match_stack.top() == '(')
          match_stack.pop();
        else
          return false;
      } else if (s[i] == ']') {
        if (match_stack.top() == '[')
          match_stack.pop();
        else
          return false;
      } else if (s[i] == '}') {
        if (match_stack.top() == '{')
          match_stack.pop();
        else
          return false;
      } else
        return false;
    }
    if (match_stack.empty())
      return true;
    else
      return false;
  }
};
