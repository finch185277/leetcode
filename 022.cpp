class Solution {
public:
  vector<string> generateParenthesis(int n) {
    std::vector<std::string> ret;
    if (n == 0)
      ret.push_back("");
    else {
      for (int i = 0; i < n; i++)
        for (std::string left : generateParenthesis(i))
          for (std::string right : generateParenthesis(n - 1 - i))
            ret.push_back("(" + left + ")" + right);
    }
    return ret;
  }
};
