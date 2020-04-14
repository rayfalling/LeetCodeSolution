//Dp»á³ö´í
class Solution {
public:
    int cuttingRope(int n) {
        return greed(n);
    }

    int greed(int n) {
        long answer = 1;
        if (n <= 3) return n - 1;
        while (n != 0) {
            if (n > 4) {
                answer *= 3;
                n -= 3;
            }
            else {
                answer *= n;
                n = 0;
            }
            answer %= int(1e9 + 7);
        }
        return answer;
    }
};