#include <queue>
#include <deque>

class MaxQueue {
public:
	std::queue<int> q;
	std::deque<int> d;

	MaxQueue() {
	}

	int max_value() {
		if (q.empty()) {
			return -1;
		}
		return d.front();
	}

	void push_back(int value) {
		q.push(value);
		while (!d.empty() && d.back() < value) {
			d.pop_back();
		}
		d.push_back(value);
	}

	int pop_front() {
		if (q.empty()) {
			return -1;
		}
		const auto res = q.front();
		if (d.front() == res) {
			d.pop_front();
		}
		q.pop();
		return res;
	}
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

// int main_队列的最大值() {
// 	MaxQueue* obj = new MaxQueue();
// 	obj->push_back(1);
// 	obj->push_back(2);
// 	int param_1 = obj->max_value();
// 	int param_2 = obj->pop_front();
// 	int param_3 = obj->max_value();
// 	return 1;
// }