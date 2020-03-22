#include <string>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(std::string s) {
	    std::unordered_map<char, int> count;
	    auto ans = 0;
        for (auto c : s)
            ++count[c];
        for (const auto p : count) {
	        const auto cnt = p.second;
        	//�ڻ����������Ҹ����ִ���
            ans += cnt / 2 * 2;
            if (cnt % 2 == 1 and ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};
