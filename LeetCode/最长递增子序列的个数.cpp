#include <algorithm>
#include <vector>

class Solution {
public:
	int findNumberOfLIS(std::vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 1;
		const int size = nums.size();
		//dp储存当前的长度和数组个数
		auto max = 0;
		std::vector<std::pair<int, int>> dp(size, {1, 1});
		for (auto i = 1; i < size; i++) {
			for (auto j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (dp[i].first < dp[j].first + 1) {
						dp[i] = {dp[j].first + 1, dp[j].second};
					}
					else if (dp[i].first == dp[j].first + 1) {
						dp[i].second += dp[j].second;
					}
				}
			}
			max = std::max(max, dp[i].first);
		}
		auto res = 0;
		for (auto i = 0; i < size; ++i) {
			if (dp[i].first == max) {
				res += dp[i].second;
			}
		}
		return res;
	}
};
