#include <vector>

class Solution {
public:
	int findRepeatNumber(std::vector<int>& nums) {
		/*int map[100000] = { 0 };
		for (int i = 0; i < nums.size(); i++) {
			if (++map[nums[i]] >= 2)return nums[i];
		}*/

		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != i) {
				if (nums[i] == nums[nums[i]]) {
					return nums[i];
				}
				int temp = nums[i];
				nums[i] = nums[temp];
				nums[temp] = temp;
			}
		}
		return -1;
	}
};

int main_数组中重复的数字() {
	std::vector<int> vec({ 0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
	Solution s;
	s.findRepeatNumber(vec);
	return 1;
}