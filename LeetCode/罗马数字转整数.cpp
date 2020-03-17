#include <string>
#include <unordered_map>

class Solution {
public:
	//组合数是固定的，所以可以直接查表
    int romanToInt(std::string s) {
	    std::unordered_map<std::string, int> m = { {"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000} };
	    auto r = m[s.substr(0, 1)];
        for (auto i = 1; i < s.size(); ++i) {
	        auto two = s.substr(i - 1, 2);
	        auto one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};
