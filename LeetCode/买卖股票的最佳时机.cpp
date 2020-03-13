#include <algorithm>
#include <vector>

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		//��������Ϊһ������
		if (prices.size() <= 1)return 0;

		//����ÿ�ռ۸��ֵ
		std::vector<int> diff(prices.size());
		for (auto i = 0; i < diff.size() - 1; i++) {
			diff[i] = prices[i + 1] - prices[i];
		}

		//dpת�������������������
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


int main_������Ʊ�����ʱ��() {
	Solution s;
	std::vector<int> test = {7, 1, 5, 3, 6, 4};
	s.maxProfit(test);
	return 1;
}
