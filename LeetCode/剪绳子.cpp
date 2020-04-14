#include <algorithm>
#include <vector>

class Solution {
public:
    int dp[60] = { 0 };
    int cuttingRope(int n) {
        if (n <= 1) return n;
        auto dp = std::vector<int>(n+1,0);
        dp[1] = 1;
        for (auto i = 2; i <= n; ++i) {
            if (i != n) dp[i] = std::max(dp[i], i); //ȡ�ضϳ���ֵ������ӳ˻��ͽضϳ��ȼ�����ֵ
            for (auto j = 1; j <= i / 2; ++j) { //ȡǰһ���ֵ�Ϳ�����
                dp[i] = std::max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
};
