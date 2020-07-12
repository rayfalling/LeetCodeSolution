#include <algorithm>
#include <vector>

class Solution {
public:
	void dfs(std::vector<std::vector<int>>& tree, std::vector<int>& informTime, int id, int time, int& ans) {
		if (tree[id].empty()) {
			ans = std::max(ans, time);
			return;
		}
		time += informTime[id];
		for (auto& next : tree[id]) {
			dfs(tree, informTime, next, time, ans);
		}
	}

	int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
		std::vector<std::vector<int>> tree(manager.size(), std::vector<int>());
		for (auto i = 0; i < manager.size(); i++) {
			if (manager[i] == -1) {
				continue;
			}
			tree[manager[i]].push_back(i);
		}
		auto ans = 0;
		dfs(tree, informTime, headID, 0, ans);
		return ans;
	}
};
