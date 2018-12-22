class Solution {
public:
  int reverse(int x) {
    double ret = 0; // double for bigger num
    int lb = pow(-2, 31), ub = pow(2, 31) - 1;

    while (x) {
      ret += (x % 10);
      ret *= 10;
      x /= 10;
    }
    ret /= 10;

    if (ret > ub || ret < lb)
      return 0;
    else
      return ret;
  }
};
