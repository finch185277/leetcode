class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    std::vector<int> num_vec;
    while (x > 0) {
      num_vec.push_back(x % 10);
      x /= 10;
    }
    int num_len = num_vec.size();
    for (int i = 0; i < num_len / 2; i++) {
      if (num_vec.at(i) != num_vec.at(num_len - i - 1))
        return false;
    }
    return true;
  }
};
