#include <vector>

class Solution {
	//题解里面建议用异或运算完成
public:
	std::vector<int> singleNumbers(std::vector<int>& nums) {
		int cnt[10001] = {0};
		for (auto c : nums) {
			cnt[c]++;
		}
		nums.clear();
		for (auto i = 0; i < 10001; i++) {
			if (cnt[i] == 1)nums.push_back(i);
		}
		return nums;
	}


	//异或解法
    // int[] singleNumbers(int[] nums) {
    //     int xorNumber = nums[0];
    //     for (int k = 1; k < nums.length; k++) {
    //         xorNumber ^= nums[k];
    //     }
    //     int onePosition = xorNumber & (-xorNumber);
    //     int ans1 = 0, ans2 = 0;
    //     for (int i = 0; i < nums.length; i++) {
    //         if ((nums[i] & onePosition) == onePosition) {
    //             ans1 ^= nums[i];
    //         }
    //         else {
    //             ans2 ^= nums[i];
    //         }
    //     }
    //
    //     return new int[] {ans1 ^ 0, ans2 ^ 0};
    // }
};
