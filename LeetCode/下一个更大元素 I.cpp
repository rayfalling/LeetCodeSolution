#include <map>
#include <stack>
#include <vector>

class Solution {
public:
	std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::map<int, int> mp;
		std::stack<int> stack;

        for (int value : nums1) {
            mp[value] = -1;
        }

        for (auto i : nums2) {
            while (!stack.empty() && stack.top() < i) {
                mp[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }

        for (auto& i : nums1) {
	        i = mp[i];
        }
        return nums1;
    }
};
