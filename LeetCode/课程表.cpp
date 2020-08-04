#include <vector>

class Solution {
	static bool is_empty(const std::vector<int>& list) {
		for (auto i : list) {
			if (i != -1)
				return false;
		}
		return true;
	}

	static bool dfs(std::vector<std::vector<int>>& course, std::vector<std::vector<int>>& visit, const int current) {
		for (auto index = 0; index < course[current].size(); index++) {
			if (course[current][index] != -1) {
				if (visit[current][index] == 1) {
					return false;
				}
				visit[current][index] = 1;

				if (dfs(course, visit, course[current][index])) {
					course[current][index] = -1;
					visit[current][index] = 0;
				}
			}
		}
		return is_empty(course[current]);
	}

public:
	bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
		std::vector<std::vector<int>> course(numCourses, std::vector<int>());
		std::vector<std::vector<int>> visit(numCourses, std::vector<int>());
		for (auto prerequisite : prerequisites) {
			course[prerequisite[0]].emplace_back(prerequisite[1]);
			visit[prerequisite[0]].emplace_back(0);
		}

		auto result = true;
		for (auto index = 0; index < numCourses; index++) {
			result = result && dfs(course, visit, index);
		}

		return result;
	}
};

int main() {
	std::vector<std::vector<int>> course = {{1, 0}};
	// std::vector<std::vector<int>> course = {{1, 0}, {0, 2}, {2, 1}};
	Solution().canFinish(2, course);
	// Solution().canFinish(3, course);
	return 0;
}
