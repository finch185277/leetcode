// leetcode : 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <utility> // std::pair, std::make_pair

static bool comp(std::pair<int, int>a, std::pair<int, int>b)
{
        if (a.first <= b.first)
        {
                if (a.first == b.first)
                {
                        return a.second < b.second;
                }
                return true;
        }
        return false;
}

class Solution {
public:
int findMinArrowShots(std::vector< std::pair<int, int> >& points) {
        int ret = 1;
        sort(points.begin(), points.end(), comp);
        int length = points.size();
        if (length == 0)
        {
                return 0;
        }
        std::pair<int, int> standard = points[0];
        for (int i = 1; i < length; i++)
        {
                if (points[i].first <= standard.second)
                {
                        if (points[i].second <= standard.second)
                        {
                                standard = points[i];
                        }
                        else
                        {
                                standard.first = points[i].first;
                        }
                }
                else
                {
                        ret++;
                        standard = points[i];
                }
        }
        return ret;
}
};

int main() {
        std::string line;
        Solution solution;
        while (std::getline(std::cin, line))
        {
                std::vector< std::pair<int, int> > numberVector;
                std::replace(line.begin(), line.end(), '[', ' ');
                std::replace(line.begin(), line.end(), ']', ' ');

                std::stringstream ss;
                ss << line;
                std::string nums;
                std::pair<int, int> tempPair;
                std::pair<bool, bool> checkPair (false, false);
                while (std::getline(ss, nums, ','))
                {
                        try
                        {
                                int x = std::stoi(nums);

                                if(checkPair.first == false) {
                                        tempPair.first = x;
                                        checkPair.first = true;
                                } else {
                                        tempPair.second = x;
                                        checkPair.second = true;
                                }

                                if (checkPair.second == true) {
                                        numberVector.push_back(tempPair);
                                        checkPair.first = false;
                                        checkPair.second = false;
                                }
                        } catch (std::invalid_argument const & e) {}

                }
                int output = solution.findMinArrowShots(numberVector);
                std::cout << output << std::endl;
        }
        return 0;
}
