/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
  inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

public: // by @lyly12
  int maxPoints(std::vector<std::vector<int>> &points) {
    if (points.size() <= 2)
      return points.size();
    int ret = 0;
    std::vector<Point *> ps;
    for (auto &p : points)
      ps.push_back(new Point(p.at(0), p.at(1)));
    for (int i = 0; i < ps.size(); i++) {
      int n = 1;
      std::map<std::pair<int, int>, int> mp;
      for (int j = i + 1; j < ps.size(); j++) {
        int dx = ps.at(i)->x - ps.at(j)->x, dy = ps.at(i)->y - ps.at(j)->y;
        if (dx == 0 && dy == 0)
          n++;
        else if (dx == 0)
          mp[std::make_pair(0, 1)]++;
        else if (dy == 0)
          mp[std::make_pair(1, 0)]++;
        else
          mp[std::make_pair(dx / gcd(dx, dy), dy / gcd(dx, dy))]++;
      }
      ret = std::max(ret, n);
      for (auto &p : mp)
        ret = std::max(ret, p.second + n);
    }
    return ret;
  }
};
