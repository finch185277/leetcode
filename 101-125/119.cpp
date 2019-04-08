class Solution {
public: // by @LongsPeak
  std::vector<int> getRow(int numRows) {
    std::vector<int> ret(numRows + 1, 0);
    ret.front() = 1;
    for (int i = 1; i <= numRows; i++)
      for (int j = i; j >= 1; j--)
        ret.at(j) += ret.at(j - 1);
    return ret;
  }
};
