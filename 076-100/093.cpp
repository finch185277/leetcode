class Solution {
private:
  inline bool is_valid(const std::string &s) {
    if (s.size() > 3 || s.size() == 0 || (s[0] == '0' && s.size() > 1) ||
        std::stoi(s) > 255)
      return false;
    else
      return true;
  }

public: // by @fiona_mao
  vector<string> restoreIpAddresses(string s) {
    std::vector<std::string> ret;
    for (int i = 1; i < 4 && i < s.size() - 2; i++)
      for (int j = i + 1; j < i + 4 && j < s.size() - 1; j++)
        for (int k = j + 1; k < j + 4 && k < s.size(); k++)
          if (is_valid(s.substr(0, i)) && is_valid(s.substr(i, j - i)) &&
              is_valid(s.substr(j, k - j)) &&
              is_valid(s.substr(k, s.size() - k)))
            ret.push_back(s.substr(0, i) + '.' + s.substr(i, j - i) + '.' +
                          s.substr(j, k - j) + '.' + s.substr(k, s.size() - k));
    return ret;
  }
};
