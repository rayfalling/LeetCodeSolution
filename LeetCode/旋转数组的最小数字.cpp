#include <vector>

class Solution {
public:
	int minArray(std::vector<int>& numbers) {
		int size = numbers.size() - 1;
		while (size > 0) {
			if (numbers[size] >= numbers[size - 1])size--;
			else return numbers[size];
		}
		return numbers[0];
	}
};
