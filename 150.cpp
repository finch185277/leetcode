class Solution {
public: // by @hercule24
  int evalRPN(std::vector<std::string> &tokens) {
    std::unordered_map<std::string, function<int(int, int)>> mp = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}};
    std::stack<int> stk;
    for (std::string &s : tokens) {
      if (!mp.count(s))
        stk.push(std::stoi(s));
      else {
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();
        stk.push(mp[s](a, b));
      }
    }
    return stk.top();
  }
};
