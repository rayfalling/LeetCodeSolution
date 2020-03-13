#include <algorithm>
#include <vector>

class Solution {
public:
	//dp实现最大子序列和
	int maxSubArray(std::vector<int>& nums) {
		std::vector<int> subMax(nums.size());
		auto max = subMax[0] = nums[0];
		for (auto i = 1; i < nums.size(); i++) {
			subMax[i] = std::max(nums[i], subMax[i - 1] + nums[i]);
			max = std::max(max, subMax[i]);
		}
		return max;
	}
};

int main_最大子序和() {
	Solution s;
	std::vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	s.maxSubArray(test);
	return 1;
}
