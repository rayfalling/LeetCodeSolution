#include <vector>

class Solution {
public:
	int fib(int n) {
		std::vector<int> v(n + 2, 0);
		v[1] = 1;
		for (auto i = 2; i <= n; i++)
			v[i] = (v[i - 1] % 1000000007 + v[i - 2] % 1000000007) % 1000000007;
		return v[n];
	}
};
