#include <vector>

class Solution {
public:
	int numWays(int n) {
		//n==0Ê±·µ»Ø1
		std::vector<int> v(n + 3, 1);
		v[2] = 2;
		for (auto i = 3; i <= n; i++)
			v[i] = (v[i - 1] % 1000000007 + v[i - 2] % 1000000007) % 1000000007;
		return v[n];
	}
};
