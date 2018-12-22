class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int l1 = nums1.size(), l2 = nums2.size();
    if (l1 > l2) { // ensure l1 <= l2
      std::swap(nums1, nums2);
      std::swap(l1, l2);
    }
    int min_idx = 0, max_idx = l1, half_len = (l1 + l2 + 1) / 2;
    while (min_idx <= max_idx) {
      int i = (min_idx + max_idx) / 2;
      int j = half_len - i;
      if (i < max_idx && nums2.at(j - 1) > nums1.at(i)) {
        min_idx = i + 1; // i too small
      } else if (i > min_idx && nums1.at(i - 1) > nums2.at(j)) {
        max_idx = i - 1; // i too big
      } else {           // i is perfect
        int left_max = 0;
        if (i == 0) {
          left_max = nums2.at(j - 1);
        } else if (j == 0) {
          left_max = nums1.at(i - 1);
        } else {
          left_max = std::max(nums1.at(i - 1), nums2.at(j - 1));
        }
        if ((l1 + l2) % 2 == 1) {
          return left_max;
        }

        int right_min = 0;
        if (i == l1) {
          right_min = nums2.at(j);
        } else if (j == l2) {
          right_min = nums1.at(i);
        } else {
          right_min = std::min(nums2.at(j), nums1.at(i));
        }

        return (double)(left_max + right_min) / 2;
      }
    }
    return 0.0;
  }
};
