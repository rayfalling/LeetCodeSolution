#include <stack>

class CQueue {
public:
	std::stack<int> a;
	std::stack<int> b;

	CQueue() {

	}

	void appendTail(int value) {
		a.push(value);
	}

	int deleteHead() {
		if (b.empty() && a.empty())
			return -1;
		if (b.empty() && !a.empty()) {
			while (!a.empty()) {
				b.push(a.top());
				a.pop();
			}
		}
		const auto temp = b.top();
		b.pop();
		return temp;
	}
};
