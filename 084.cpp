class Solution {
private:
  int max_combine_area(const std::vector<int> &heights, const int lb,
                       const int mid, const int hb) {
    int i = mid, j = mid + 1, area = 0,
        h = std::min(heights.at(i), heights.at(j));
    while (i >= lb && j <= hb) {
      h = std::min(h, std::min(heights.at(i), heights.at(j)));
      area = std::max(area, (j - i + 1) * h);
      if (i == lb)
        j++;
      else if (j == hb)
        i--;
      else {
        if (heights.at(i - 1) > heights.at(j + 1))
          i--;
        else
          j++;
      }
    }
    return area;
  }
  int max_area(const std::vector<int> &heights, const int lb, const int hb) {
    if (lb == hb)
      return heights.at(lb);
    int mid = lb + (hb - lb) / 2;
    int area = std::max(
        max_combine_area(heights, lb, mid, hb),
        std::max(max_area(heights, lb, mid), max_area(heights, mid + 1, hb)));
    return area;
  }

public: // by @gildorwang
  int largestRectangleArea(vector<int> &heights) {
    if (heights.empty())
      return 0;
    return max_area(heights, 0, heights.size() - 1);
  }
};
