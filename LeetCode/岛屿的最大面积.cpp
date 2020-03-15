#include <algorithm>
#include <vector>

class Solution {
	std::vector<std::vector<bool>> visitor_;
	std::vector<std::vector<int>> map_;

	int dfs(int i, int j) {
		if (map_[i][j] && !visitor_[i][j]) {
			auto res = 0;
			visitor_[i][j] = true;
			if (i > 0)res += dfs(i-1, j);
			if (i < map_.size() - 1)res += dfs(i+1, j);
			if (j < map_[i].size() - 1)res += dfs(i, j+1);
			if (j > 0)res += dfs(i, j-1);
			return ++res;
		}
		return 0;
	};
public:
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
		map_ = grid;
		visitor_ = std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(), false));
		auto cnt = 0, ans = 0;
		for (auto i = 0; i < visitor_.size(); i++) {
			for (auto j = 0; j < visitor_[i].size(); j++) {
				if (map_[i][j] && !visitor_[i][j]) {
					ans = std::max(ans, dfs(i, j));
				}
			}
		}
		return ans;
	}
};


int main_岛屿的最大面积() {
	std::vector<std::vector<int>> input = {
		{1, 1, 0, 1, 1},
		{1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1}
	};
	Solution s;
	s.maxAreaOfIsland(input);
	return 0;
}
