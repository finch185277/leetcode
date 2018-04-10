// leetcode : 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
public:
int singleNonDuplicate(std::vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while(l < h) {
                int m = l + (h - l) / 2;
                if(m % 2 == 1) m--;
                if(nums.at(m) == nums.at(m + 1)) l = m + 2;
                else h = m;
        }
        return nums.at(h);
}
};

int main() {
        std::string line;
        Solution solution;
        while (std::getline(std::cin, line))
        {
                std::vector<int> numberVector(50000);
                std::replace(line.begin(), line.end(), '[', ' ');
                std::replace(line.begin(), line.end(), ']', ',');
                std::stringstream ss;
                ss << line;
                std::string nums;
                while (std::getline(ss, nums, ','))
                {
                        try
                        {
                                int x = std::stoi(nums);
                                numberVector.push_back(x);
                        } catch (std::invalid_argument const & e) {}

                }
                int output = solution.singleNonDuplicate(numberVector);
                std::cout << output << std::endl;
        }
        return 0;
}
