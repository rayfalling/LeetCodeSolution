#include <vector>
#include <queue>
#include <set>

class Solution {
public:
	/*
	 * 因为树的高度最小，所以是最长链中间折半
	 * 即根节点为最长链的中间节点，可能为一个或者两个
	 */
	std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
		//特判n为1的时候
		if (n == 1)return {0};
		//创建矩阵图
		std::vector<std::set<int>> maps(n);
		//从输入生成图
		for (auto edge : edges) {
			maps[edge[0]].insert(edge[1]);
			maps[edge[1]].insert(edge[0]);
		}
		//当前搜索的节点
		std::queue<int> q;
		//循环找所有叶子节点
		for (auto i = 0; i < n; i++) {
			//找到所有的叶子节点
			if (maps[i].size() == 1)
				q.push(i);
		}

		//n > 2的时候
		while (n > 2) {
			//取出所有叶子节点的数量
			const int size = q.size();
			//使n为根节点的数量
			n -= size;
			for (auto i = 0; i < size; i++) {
				//获取第一个叶子节点
				auto front = q.front();
				q.pop();
				//从叶子节点开始搜索父节点，获取最长链
				for (auto item : maps[front]) {
					//删除已搜索的节点的边连接
					maps[item].erase(front);
					//如果删除后为叶子节点，添加到叶子节点的搜索队列中
					if (maps[item].size() == 1) {
						q.push(item);
					}
				}
			}
		}

		std::vector<int> ans;
		//剩下的节点基本为最长链的中间节点，即所求根节点
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
	}
};

int main_最小高度树() {
	Solution s;
	std::vector<std::vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
	s.findMinHeightTrees(4, edges);
	return 0;
}
