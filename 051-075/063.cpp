class Solution {
public: // by Approach 1: Dynamic Programming
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid.front().size();
    if (obstacleGrid.at(0).at(0) == 1)
      return 0;
    obstacleGrid.at(0).at(0) = 1;
    for (int i = 1; i < m; i++) { // fill values of first column
      if (obstacleGrid.at(i).at(0) == 0 && obstacleGrid.at(i - 1).at(0) == 1)
        obstacleGrid.at(i).at(0) = 1;
      else
        obstacleGrid.at(i).at(0) = 0;
    }
    for (int j = 1; j < n; j++) { // fill values of first row
      if (obstacleGrid.at(0).at(j) == 0 && obstacleGrid.at(0).at(j - 1) == 1)
        obstacleGrid.at(0).at(j) = 1;
      else
        obstacleGrid.at(0).at(j) = 0;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid.at(i).at(j) == 0)
          obstacleGrid.at(i).at(j) =
              obstacleGrid.at(i - 1).at(j) + obstacleGrid.at(i).at(j - 1);
        else
          obstacleGrid.at(i).at(j) = 0;
      }
    }
    return obstacleGrid.back().back();
  }
};
