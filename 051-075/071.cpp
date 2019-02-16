class Solution {
public: // by @monaziyi
  string simplifyPath(string path) {
    std::string str, ret;
    std::vector<std::string> dirs;
    std::stringstream ss(path);
    while (std::getline(ss, str, '/')) {
      if (str.empty() || str == ".")
        continue;
      else if (str == ".." && !dirs.empty())
        dirs.pop_back();
      else if (str != "..")
        dirs.push_back(str);
    }
    for (std::string dir : dirs)
      ret += '/' + dir;
    return ret.empty() ? "/" : ret;
  }
};
