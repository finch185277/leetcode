class Solution {
public:
  int reverse(int x) {
    double ret = 0;
    int lb = pow(-2, 31), ub = pow(2, 31) - 1;
    bool neg_flag = false;
    std::queue<int> q;
    if (x == lb)
      return 0;

    while (x) {
      q.push(x % 10);
      x /= 10;
      ret += q.front();
      q.pop();
      ret *= 10;
    }
    ret /= 10;

    if (ret > ub || ret <= lb)
      return 0;
    else
      return ret;
  }
};
