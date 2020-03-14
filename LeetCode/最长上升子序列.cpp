#include <algorithm>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
	    const auto n = static_cast<int>(nums.size());
        if (n == 0) return 0;
        std::vector<int> dp(n, 0);
        for (auto i = 0; i < n; i++) {
            dp[i] = 1;
            for (auto j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
