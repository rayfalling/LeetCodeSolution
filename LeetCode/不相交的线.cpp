#include <algorithm>
#include <vector>

class Solution {
public:
	/**
	 * 返回两个数组中相同数字不相交的最大连线数
	 * @param A int整型vector 整数集合A
	 * @param B int整型vector 整数集合B
	 * @return int整型
	 */

	//dp问题
	int maxUncrossedLines(std::vector<int>& A, std::vector<int>& B) {
		std::vector<std::vector<int>> dp(A.size() + 1, std::vector<int>(B.size() + 1, 0));
		for (auto i = 0; i < A.size(); i++) {
			for (auto j = 0; j < B.size(); j++) {
				if (A[i] == B[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				else {
					dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
				}
			}

		}
		return dp[A.size()][B.size()];
	}
};
