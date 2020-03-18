#include <set>
#include <vector>

class Solution {
public:
	std::vector<int> powerfulIntegers(int x, int y, int bound) {
	    std::vector<int> ans;
        std::set<int> s;
        if (x == 1 && y == 1) {
            if (2 <= bound)
                ans.push_back(2);
            return ans;
        }

        // 始终令y!=1而x=1
        if (y == 1) {
            y = x;
            x = 1;
        }
        auto tmp_x = 1;

        for (auto i = 0; i < bound; i++) {
	        auto tmp_y = 1;
            for (auto j = 0; j < bound; j++) {
	            auto elem = tmp_x + tmp_y;
                if (elem <= bound) {
                    s.insert(elem);
                    tmp_y *= y;       //计算y的乘方
                }
                else
                    break;
            }

            // 外层循环剪枝：当仅仅x的幂次就达到bound时，不需要继续计算下去
            //  当x==1时，也不需要再继续计算下去。
            if (pow(x, i) >= bound || x == 1)
                break;
            tmp_x *= x;           //计算x的乘方
        }
        auto iter = s.begin();
        while (iter != s.end()) {
            ans.push_back(*iter);
            iter++;
        }
        return ans;
    }
};
