#include <unordered_set>
#include <vector>

//利用哈希表的冲突来处理问题
class Solution {
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
		std::unordered_set<int> set;
		for (auto i = 0; i < nums.size(); i++) {
			if (set.find(nums[i]) != set.end()) {
				return true;
			}
			set.insert(nums[i]);
			if (set.size() > k) {
				set.erase(nums[i - k]);
			}
		}
		return false;
	}
};

int main_存在重复元素_II() {
	Solution s;
	std::vector<int> vec = {1, 2, 3, 1, 2, 3};
	s.containsNearbyDuplicate(vec, 2);
	return 0;
}
