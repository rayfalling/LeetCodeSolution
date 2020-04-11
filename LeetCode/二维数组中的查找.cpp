#include <vector>

class Solution {
public:
	bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())return false;
		const auto row_size = matrix.size();
		auto i = 0, j = static_cast<int>(matrix[0].size() - 1);
		while (i < row_size && j >= 0) {
			if (matrix[i][j] == target) {
				return true;
			}
			if (matrix[i][j] > target) {
				j--;
			}
			else if (matrix[i][j] < target) {
				i++;
			}
		}
		return false;
	}
};

int main_二维数组中的查找() {
	std::vector<std::vector<int>> test = {{-5}};
	Solution().findNumberIn2DArray(test, -10);
	return 0;
}
