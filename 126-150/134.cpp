class Solution {
public: // by @daxianji007
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int start(0), total(0), tank(0);
    for (int i = 0; i < gas.size(); i++) {
      tank += gas.at(i) - cost.at(i);
      if (tank < 0) {
        start = i + 1;
        total += tank;
        tank = 0;
      }
    }
    return (total + tank < 0) ? -1 : start;
  }
};
