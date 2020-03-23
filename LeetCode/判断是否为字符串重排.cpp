#include <algorithm>
#include <string>

class Solution {
public:
    bool CheckPermutation(std::string s1, std::string s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};