#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> um;
        for (auto i = 0; i < nums.size(); i++) um[nums[i]].push_back(i);
        int nums_du = 0, minlen;
        for (auto i : um) {
            const int size = i.second.size();
            if (size >= nums_du) {
                auto temp = i.second[size - 1] - i.second[0] + 1;
                if (size > nums_du) {
                    nums_du = size;
                    minlen = temp;
                }
                else minlen = std::min(minlen, temp);
            }
        }
        return minlen;
    }
};
