class Solution {
private:
  inline long long c_n_choose_k(int n, int k) {
    if (k > n)
      return 0;
    if (k * 2 > n)
      k = n - k;
    if (k == 0)
      return 1;

    long long result = n;
    for (int i = 2; i <= k; i++) {
      result *= ((n - i) + 1);
      result /= i;
    }
    return result;
  }

public:
  int uniquePaths(int m, int n) { return c_n_choose_k(m - 1 + n - 1, m - 1); }
};
