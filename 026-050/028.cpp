class Solution {
public:
  int strStr(string haystack, string needle) {
    int haystack_len = haystack.size(), needle_len = needle.size();
    if (haystack_len == 0 && needle_len == 0)
      return 0;
    for (int i = 0; i < haystack_len - needle_len + 1; i++)
      if (needle == haystack.substr(i, needle_len))
        return i;
    return -1;
  }
};
