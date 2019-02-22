class Solution {
public: // by @sipiprotoss5
  int largestRectangleArea(vector<int> &heights) {
    int ret = 0;
    heights.push_back(0);
    std::vector<int> index;
    for (int i = 0; i < heights.size(); i++) {
      while (index.size() > 0 && heights.at(index.back()) > heights.at(i)) {
        int h = heights.at(index.back());
        index.pop_back();
        int sidx = index.size() > 0 ? index.back() : -1;
        if (h * (i - sidx - 1) > ret)
          ret = h * (i - sidx - 1);
      }
      index.push_back(i);
    }
    return ret;
  }
};
