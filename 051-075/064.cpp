class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    for (int i = 1; i < grid.size(); i++) // fill first column
      grid.at(i).at(0) += grid.at(i - 1).at(0);
    for (int j = 1; j < grid.front().size(); j++) // fill first row
      grid.at(0).at(j) += grid.at(0).at(j - 1);
    for (int i = 1; i < grid.size(); i++) // fill the grid
      for (int j = 1; j < grid.front().size(); j++)
        grid.at(i).at(j) +=
            std::min(grid.at(i - 1).at(j), grid.at(i).at(j - 1));
    return grid.back().back();
  }
};
