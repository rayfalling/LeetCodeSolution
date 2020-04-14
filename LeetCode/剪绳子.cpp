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
            if (i != n) dp[i] = std::max(dp[i], i); //取截断长度值的最大子乘积和截断长度间的最大值
            for (auto j = 1; j <= i / 2; ++j) { //取前一半的值就可以了
                dp[i] = std::max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
};
