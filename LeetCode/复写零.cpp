#include <vector>

class Solution {
public:
	void duplicateZeros(std::vector<int>& arr) {
		const auto size = arr.size();
		for (auto i = 0; i < size; i++) {
			if (arr[i] == 0) {
				arr.pop_back();
				arr.insert(arr.begin() + i, 0);
				i++;
			}
		}
	}
};
