/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
  inline static bool sort_intervals(const Interval &lhs, const Interval &rhs) {
    return lhs.start < rhs.start;
  }

public: // by @lchen77
  vector<Interval> merge(vector<Interval> &intervals) {
    std::vector<Interval> ret;
    if (intervals.empty())
      return ret;
    std::sort(intervals.begin(), intervals.end(), sort_intervals);
    ret.push_back(intervals.at(0));
    for (int i = 1; i < intervals.size(); i++) {
      if (ret.back().end < intervals.at(i).start) // they are diff intervals
        ret.push_back(intervals.at(i));
      else // enlarge the interval size to cover the overlapping area
        ret.back().end = std::max(ret.back().end, intervals.at(i).end);
    }
    return ret;
  }
};
