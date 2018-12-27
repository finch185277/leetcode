class Solution {
public:
  inline bool isValid(string &s) {
    std::stack<char> match_stack;
    for (int i = 0; i < s.size(); i++) {
      if (match_stack.empty() || s[i] == '(')
        match_stack.push(s[i]);
      else if (s[i] == ')') {
        if (match_stack.top() == '(')
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
  vector<string> generateParenthesis(int n) {
    std::vector<std::string> ret;
    std::vector<char> recur;
    for (int i = 0; i < n; i++) {
      recur.insert(recur.begin(), '(');
      recur.push_back(')');
    }
    do {
      std::string str(recur.begin(), recur.end());
      if (isValid(str))
        ret.push_back(str);
    } while (std::next_permutation(recur.begin(), recur.end()));
    return ret;
  }
};
