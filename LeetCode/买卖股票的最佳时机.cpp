#include <algorithm>
#include <vector>

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		//特判输入为一天的情况
		if (prices.size() <= 1)return 0;

		//建立每日价格差值
		std::vector<int> diff(prices.size());
		for (auto i = 0; i < diff.size() - 1; i++) {
			diff[i] = prices[i + 1] - prices[i];
		}

		//dp转移求解子序列最大和问题
		std::vector<int> dp(diff.size());
		dp[0] = std::max(0, diff[0]);
		auto profit = dp[0];
		for (auto i = 1; i < diff.size(); i++) {
			dp[i] = std::max(0, diff[i] + dp[i - 1]);
			profit = std::max(profit, dp[i]);
		}
		return profit;
	}
};


int main_买卖股票的最佳时机() {
	Solution s;
	std::vector<int> test = {7, 1, 5, 3, 6, 4};
	s.maxProfit(test);
	return 1;
}
