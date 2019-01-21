class Solution {
public:
  int trap(vector<int> &height) {
    int ret = 0, cur = 0;
    std::stack<int> stk;
    while (cur < height.size()) {
      while (!stk.empty() && height.at(cur) > height.at(stk.top())) {
        int top = stk.top();
        stk.pop();
        if (!stk.empty()) { // if stack empty, left bound is not exist
          int distance = cur - stk.top() - 1;
          int bounded_height = // the height of water layer
              std::min(height.at(cur), height.at(stk.top())) - height.at(top);
          ret += distance * bounded_height;
        }
      }
      stk.push(cur++);
    }
    return ret;
  }
};
