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

        // ʼ����y!=1��x=1
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
                    tmp_y *= y;       //����y�ĳ˷�
                }
                else
                    break;
            }

            // ���ѭ����֦��������x���ݴξʹﵽboundʱ������Ҫ����������ȥ
            //  ��x==1ʱ��Ҳ����Ҫ�ټ���������ȥ��
            if (pow(x, i) >= bound || x == 1)
                break;
            tmp_x *= x;           //����x�ĳ˷�
        }
        auto iter = s.begin();
        while (iter != s.end()) {
            ans.push_back(*iter);
            iter++;
        }
        return ans;
    }
};
