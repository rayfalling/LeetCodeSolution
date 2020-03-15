#include <algorithm>
#include <vector>

class Solution {
public:
	int minIncrementForUnique(std::vector<int>& A) {
		if (A.empty())return 0;
		std::sort(A.begin(), A.end());
		auto cnt = 0;
		auto cur = A[0];
		for (auto i : A) {
			if (i <= cur) {
				cnt += cur - i;
			}
			else {
				cur = i;
			}
			cur++;
		}
		return cnt;
	}
};
