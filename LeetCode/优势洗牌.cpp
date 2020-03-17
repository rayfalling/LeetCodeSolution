#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
	//����̰��ʵ�֣���ʱ1000ms���ϣ�ʱ�临�Ӷ�����O(n^2)
	std::vector<int> advantageCount(std::vector<int>& A, std::vector<int>& B) {
		std::vector<int> ans;
		std::sort(A.begin(), A.end());
		for (auto i : B) {
			auto find = false;
			for (auto j = 0; j < A.size(); j++) {
				if (A[j] > i) {
					ans.emplace_back(A[j]);
					A.erase(A.begin() + j);
					find = true;
					break;
				}
			}
			if (!find) {
				ans.emplace_back(A[0]);
				A.erase(A.begin());
			}
		}
		return ans;
	}

	//multisetʵ�֣�ִ�к�ʱԼΪ100ms
	std::vector<int> advantageCount(std::vector<int>& A, std::vector<int>& B)
	{
		std::vector<int> ans;
		std::multiset<int> value_set(A.begin(), A.end());
		for (auto i = 0; i < A.size(); i++) {
			auto it = value_set.upper_bound(B[i]);
			if (it != value_set.end()) {
				ans.push_back(*it);
				value_set.erase(it);
			}
			else {
				ans.push_back(*value_set.begin());
				value_set.erase(value_set.begin());
			}
		}

		return ans;
	}
};

int main_����ϴ��() {
	std::vector<int> A = {2, 7, 11, 15},
	                 B = {1, 10, 4, 11};
	Solution s;
	s.advantageCount(A, B);
	return 0;
}
