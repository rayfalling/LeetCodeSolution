#include <queue>
#include <vector>

class Solution {
public:
	int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return -1;
		const int row = grid.size();
		const int col = grid[0].size();
		if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1) return -1;

		std::vector<std::vector<int>> dp(row, std::vector<int>(col, -1));
		std::vector<std::pair<int, int>> dis = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
		dp[0][0] = 1;

		std::queue<std::pair<int, int>> q;
		q.push({0, 0});

		while (!q.empty()) {
			const auto x = q.front().first;
			const auto y = q.front().second;
			q.pop();

			for (auto i = 0; i < 8; ++i) {
				auto d_x = x + dis[i].first, d_y = y + dis[i].second;

				if (d_x >= row || d_x < 0 || d_y < 0 || d_y >= col) continue;
				if (grid[d_x][d_y] == 1) continue;

				if (dp[d_x][d_y] == -1 || dp[d_x][d_y] > dp[x][y] + 1) {
					dp[d_x][d_y] = dp[x][y] + 1;
					q.push({d_x, d_y});
				}
			}
		}

		return dp[row - 1][col - 1];
	}
};
