class Solution {
private:
  bool exist(std::vector<std::vector<char>> &board, int y, int x,
             const std::string &word, int i) {
    if (i == word.size())
      return true;
    if (y < 0 || x < 0 || y == board.size() || x == board.at(y).size())
      return false;
    if (board.at(y).at(x) != word[i])
      return false;
    board.at(y).at(x) ^= 128; // bitwise (+) -> (-)
    bool exist_flag = exist(board, y, x + 1, word, i + 1) ||
                      exist(board, y, x - 1, word, i + 1) ||
                      exist(board, y + 1, x, word, i + 1) ||
                      exist(board, y - 1, x, word, i + 1);
    board.at(y).at(x) ^= 128; // bitwise (-) -> (+)
    return exist_flag;
  }

public: // by @pavel-shlyk
  bool exist(vector<vector<char>> &board, string word) {
    for (int y = 0; y < board.size(); y++)
      for (int x = 0; x < board.at(y).size(); x++)
        if (exist(board, y, x, word, 0))
          return true;
    return false;
  }
};
