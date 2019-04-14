class Solution {
public: // by @1145520074
  int candy(std::vector<int> &ratings) {
    if (ratings.size() <= 1)
      return ratings.size();
    std::vector<int> num(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++)
      if (ratings.at(i) > ratings.at(i - 1))
        num.at(i) = num.at(i - 1) + 1;
    for (int i = ratings.size() - 1; i > 0; i--)
      if (ratings.at(i - 1) > ratings.at(i))
        num.at(i - 1) = std::max(num.at(i) + 1, num.at(i - 1));
    int result(0);
    for (int &i : num)
      result += i;
    return result;
  }
};
