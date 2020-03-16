#include <algorithm>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
	bool robot(std::string command, std::vector<std::vector<int>>& obstacles, int x, int y) {
		std::set<long> s;
		auto xx = 0, yy = 0;
		s.insert(0);
		for (auto c : command) {
			if (c == 'U') yy++;
			else if (c == 'R')xx++;
			s.insert((static_cast<long>(xx) << 30) | yy);
		}

		auto circle = std::min(x / xx, y / yy);
		if (s.count((static_cast<long>(x - circle * xx) << 30) | (y - circle * yy)) == 0) return false;

		for (auto v : obstacles) {
			if (v.size() != 2) continue;
			if (v[0] > x || v[1] > y) continue;
			circle = std::min(v[0] / xx, v[1] / yy);
			if (s.count((static_cast<long>(v[0] - circle * xx) << 30) | (v[1] - circle * yy))) return false;
		}
		return true;
	}
};
