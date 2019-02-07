class Solution {
public: // by @xuewuxiao
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    std::vector<std::string> ret;
    int hb = 0;
    while (hb < words.size()) {
      int lb = hb;
      int linesize = words.at(hb++).size();
      while (hb < words.size() &&
             linesize + 1 + words.at(hb).size() <= maxWidth)
        linesize += 1 + words.at(hb++).size();
      int spaces = 1, extra = 0;
      if (hb < words.size() && hb != lb + 1) {
        spaces = (maxWidth - linesize) / (hb - lb - 1) + 1;
        extra = (maxWidth - linesize) % (hb - lb - 1);
      }
      ret.push_back(words.at(lb++));
      while (extra--) {
        ret.back().append(spaces + 1, ' ');
        ret.back().append(words.at(lb++));
      }
      while (lb < hb) {
        ret.back().append(spaces, ' ');
        ret.back().append(words.at(lb++));
      }
      ret.back().append(maxWidth - ret.back().size(), ' ');
    }
    return ret;
  }
};
