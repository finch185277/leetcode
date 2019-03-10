class Solution {
public: // by @deck
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, cur = m + n - 1;
    while (j >= 0)
      nums1.at(cur--) =
          i >= 0 && nums1.at(i) > nums2.at(j) ? nums1.at(i--) : nums2.at(j--);
  }
};
