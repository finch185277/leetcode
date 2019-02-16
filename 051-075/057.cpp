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
public: // by @StefanPochmann
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    std::vector<Interval> left, right, ret;
    for (Interval interval : intervals) {
      if (interval.end < newInterval.start)
        left.push_back(interval);
      else if (interval.start > newInterval.end)
        right.push_back(interval);
      else {
        newInterval.start = std::min(newInterval.start, interval.start);
        newInterval.end = std::max(newInterval.end, interval.end);
      }
    }
    ret.insert(ret.end(), left.begin(), left.end());
    ret.push_back(newInterval);
    ret.insert(ret.end(), right.begin(), right.end());
    return ret;
  }
};
