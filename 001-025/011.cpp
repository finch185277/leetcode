class Solution {
public:
  int maxArea(vector<int> &height) {
    if (height.size() < 2)
      return 0;
    int ret = 0, lb = 0, hb = height.size() - 1;
    while (lb < hb) {
      int tmp_area = (hb - lb) * std::min(height.at(lb), height.at(hb));
      ret = std::max(ret, tmp_area);
      if (height.at(lb) < height.at(hb)) // remain longer height
        lb++;
      else
        hb--;
    }
    return ret;
  }
};
