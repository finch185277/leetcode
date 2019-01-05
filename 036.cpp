class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      std::unordered_map<char, int> row, col;
      for (int j = 0; j < 9; j++) {
        if (board.at(i).at(j) != '.')
          row[board.at(i).at(j)]++;
        if (board.at(j).at(i) != '.')
          col[board.at(j).at(i)]++;
      }
      for (std::pair<char, int> p : row)
        if (p.second > 1)
          return false;
      for (std::pair<char, int> p : col)
        if (p.second > 1)
          return false;
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        std::unordered_map<char, int> block;
        for (int x = i * 3; x < (i + 1) * 3; x++)
          for (int y = j * 3; y < (j + 1) * 3; y++)
            if (board.at(x).at(y) != '.')
              block[board.at(x).at(y)]++;
        for (std::pair<char, int> p : block)
          if (p.second > 1)
            return false;
      }
    }
    return true;
  }
};
