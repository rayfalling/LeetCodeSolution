#include <algorithm>
#include <vector>

class Solution {
public:
	/**
	 * ����������������ͬ���ֲ��ཻ�����������
	 * @param A int����vector ��������A
	 * @param B int����vector ��������B
	 * @return int����
	 */

	//dp����
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
