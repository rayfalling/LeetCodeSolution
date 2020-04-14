#include <queue>
#include <utility>

class Solution {
    // 计算 x 的数位之和
    int get(int x) {
	    auto res = 0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        std::queue<std::pair<int, int> > Q;
        // 向右和向下的方向数组
        int dx[2] = { 0, 1 };
        int dy[2] = { 1, 0 };
        std::vector<std::vector<int> > vis(m, std::vector<int>(n, 0));
        Q.push(std::make_pair(0, 0));
        vis[0][0] = 1;
        auto ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (auto i = 0; i < 2; ++i) {
	            auto tx = dx[i] + x;
	            auto ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
                Q.push(std::make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
};
