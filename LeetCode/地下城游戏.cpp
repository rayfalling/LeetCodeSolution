#include <algorithm>
#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> memVec;

	int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
		for (auto i = 0; i < dungeon.size(); i++) {
			std::vector<int> vec;
			vec.reserve(dungeon[0].size());
			for (auto j = 0; j < dungeon[0].size(); j++) {
				vec.emplace_back(0);
			}
			memVec.push_back(vec);
			vec.clear();
		}
		return dfs(dungeon, 0, 0, dungeon.size(), dungeon[0].size()) + 1; //这里最小是0 所以生命值要+1;
	}

	int dfs(std::vector<std::vector<int>>& dungeon, int beginX, int beginY, int endX, int endY) {
		if (beginX >= endX || beginY >= endY) {
			return INT_MAX;
		}
		if (memVec[beginX][beginY] != 0) {
			return memVec[beginX][beginY];
		}
		//退出条件
		if (beginX == endX - 1 && beginY == endY - 1) {
			if (dungeon[beginX][beginY] >= 0) {
				//如果最后一个数 > 0
				return 0;
			}
			return -dungeon[beginX][beginY];
		}
		//开始递归
		const auto right_min = dfs(dungeon, beginX, beginY + 1, endX, endY);
		const auto down_min = dfs(dungeon, beginX + 1, beginY, endX, endY);
		//开始判断
		const auto need_min = std::min(right_min, down_min) - dungeon[beginX][beginY];
		//判断这里需要的生命值是否是小于0的
		const auto result = need_min < 0 ? 0 : need_min;
		memVec[beginX][beginY] = result;
		return result;
	}
};
